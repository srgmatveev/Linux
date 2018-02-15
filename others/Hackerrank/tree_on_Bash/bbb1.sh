#read n # number of iterations
n=$1;

declare -A matrix # 2D array
num_rows=63 # number of rows
num_columns=100 # columns number 
branch_length=16; # first node length
center=$(echo "${num_columns}/2"|bc)


function first_fill_matrix(){
    local num_rows=$1
    local num_columns=$2

    for ((i=1;i<=num_rows;i++)) do
	for ((j=1;j<=num_columns;j++)) do
    	    matrix[$i,$j]='_'
        done
    done
}


function fill_matrix(){
    local level=$1
    local num_rows=$2
    local num_columns=$3
    local  name=$5"[@]"
    local -a x_arr=(${!name})
    if (($level<1));then return;fi;
    local divider=$(echo "${n}-${level}+1"|bc)
    local b_length=$(echo "${branch_length}/2^(${divider}-1)"|bc)
    local quantity=$(echo "${branch_length}/${b_length}"|bc)
    local -a basis=();
    local x_pos=$4
    if((level==n)); then  basis=${x_arr}
    else 
	 local my_length=$((b_length*2));
	 x_pos=$(echo "${x_pos}-${b_length}*4"|bc)
	for ((i=0;i<"${#x_arr[@]}";i++)) do
	     local bb=$((i*2))
	     basis[$bb]=$((x_arr[i]-my_length))
	     basis[$(($bb+1))]=$((x_arr[i]+my_length))
	done;
    fi;

    for ((i=0;i<"${#basis[@]}";i++)) do
	for ((j=0;j<b_length;j++)) do
        	matrix[$((x_pos-j)),$((basis[i]))]='1'
		matrix[$((x_pos-((j+b_length)))),$((basis[i]-((j+1))))]='1'
	    matrix[$((x_pos-((j+b_length)))),$((basis[i]+((j+1))))]='1'
	done;
    done;

    fill_matrix $((level-1)) $num_rows $num_columns $x_pos basis
    return;
}



function print_matrix(){
    local num_rows=$1
    local num_columns=$2
    for ((i=1;i<=num_rows;i++)) do
	for ((j=1;j<=num_columns;j++)) do
            echo -n "${matrix[$i,$j]}"
	done
	if (($i<$num_rows)); then
	printf "\n"
	fi
    done
}

first_fill_matrix $num_rows $num_columns;
declare -a basis=($center)
fill_matrix $n $num_rows $num_columns $num_rows basis;
print_matrix $num_rows $num_columns;

