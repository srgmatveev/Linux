let reso = document.getElementById('res');

let operands = [];
let operators = [];

let tempo_str = ''; /// save temporary binary value

let lock_equal = false;

const oper = {
    add: "+",
    minus: "-",
    mul: "*",
    div: '/',
}

function action(e) {
    let pushBtn = e.target || e.srcElement;
    switch (pushBtn.id) {
        case 'btn0':
            correct_string();
            reso.innerHTML += '0';
            tempo_str += '0';
            lock_equal = false;
            break;
        case 'btn1':
            correct_string();
            reso.innerHTML += '1';
            tempo_str += '1';
            lock_equal = false;
            break;
        case 'btnClr':
            reso.innerHTML = '';
            tempo_str = '';
            operands.length = 0;
            operators.length = 0;
            lock_equal = false;


            break;
        case 'btnSum':
            if (canAddOperator()) {
                reso.innerHTML += '+';
                add_operands(oper.add);
            }
            break;
        case 'btnSub':
            if (canAddOperator()) {
                reso.innerHTML += '-';
                add_operands(oper.minus);
            }
            break;
        case 'btnMul':
            if (canAddOperator()) {
                reso.innerHTML += '*';
                add_operands(oper.mul);
            }
            break;
        case 'btnDiv':
            if (canAddOperator()) {
                reso.innerHTML += '/';
                add_operands(oper.div);
            }
            break;
        case 'btnEql':
            eval_expression();
            break;

        default:
            // statements_def
            break;
    }

}
document.getElementById('btn0').addEventListener('click', action);
document.getElementById('btn1').addEventListener('click', action);
document.getElementById('btnClr').addEventListener('click', action);
document.getElementById('btnEql').addEventListener('click', action);
document.getElementById('btnSum').addEventListener('click', action);
document.getElementById('btnSub').addEventListener('click', action);
document.getElementById('btnMul').addEventListener('click', action);
document.getElementById('btnDiv').addEventListener('click', action);

function canAddOperator() {
    let len = reso.innerHTML.length;
    const charsToSearch = ["1", "0", ];
    if (!len) return false;
    const foundChar = reso.innerHTML.charAt(len - 1);
    if (charsToSearch.indexOf(foundChar) == -1) return false;
    return true;
}

function add_operands(operator) {
    if (tempo_str.length == 0 && reso.innerHTML.length > 1) {
        operands.push(parseInt(reso.innerHTML.substr(0, reso.innerHTML.length - 1), 2));
        //  console.log('!!!!pusher!!!!');


    } else operands.push(parseInt(tempo_str, 2));
    operators.push(operator);
    tempo_str = '';
    lock_equal = false;
    console.log(operator);
}

function eval_expression() {
    if (lock_equal) return;
    let len = reso.innerHTML.length;
    const charsToSearch = ["+", "-", "*", "/", ];
    if (!len) return;
    const foundChar = reso.innerHTML.charAt(len - 1);
    if (charsToSearch.indexOf(foundChar) == -1) {
        if (operators.length == 0) {
            operands[0] = parseInt(reso.innerHTML.toString(), 2);
            tempo_str = '';
        } else {
            operands.push(parseInt(tempo_str, 2));
            tempo_str = '';
        }
    }

    // console.log('hello');
    //  console.log(operators);
    //  console.log(operands);

    if (operators.length == 0) return;
    let tt_str = '';
    for (let i = 0; i < operands.length; i++) {
        if (i < operands.length - 1) tt_str += operands[i].toString() + operators[i];
        else tt_str += operands[i].toString();

    }

    // console.log('tt_str='+tt_str);
    //console.log(eval(tt_str).toString(2));
    let tempos = eval(tt_str).toString(2);
    if (/\./.test(tempos)) {
        reso.innerHTML = Math.floor(tempos);
    } else reso.innerHTML = tempos
    lock_equal = true;
    operators.length = 0;
    operands.length = 0;
    tempo_str = '';
}

function correct_string() {

    //console.log("tempo_str"+tempo_str);
    if (tempo_str.length == 0 && reso.innerHTML.length > 1) {

        //console.log('work');
        if (/^\d+$/.test(reso.innerHTML))
            tempo_str = reso.innerHTML;
    }
    return;
}