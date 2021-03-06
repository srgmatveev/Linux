(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(default ((t (:family "DejaVu Sans Mono" :foundry "unknown" :slant normal :weight normal :height 169 :width normal)))))

;; Alarm off
(setq ring-bell-function 'ignore)


;(require 'package)
;(add-to-list 'package-archives
;             '("melpa" . "http://melpa.org/packages/") t)
;(package-initialize)
;;(require 'auto-complete)
;;(require 'auto-complete-config)
;;(ac-config-default)

(require 'package)
(setq package-enable-at-startup nil)
(add-to-list 'package-archives '("melpa" . "http://melpa.org/packages/"))
(add-to-list 'package-archives '("gnu" . "http://elpa.gnu.org/packages/"))
(package-initialize)

(require 'auto-complete)
(require 'auto-complete-config)
(ac-config-default)


(unless (package-installed-p 'use-package)
  (package-refresh-contents)
  (package-install 'use-package))

(eval-when-compile
  (require 'use-package))
;(require 'diminish)
(require 'bind-key)


;; start yasnippet with emacs
(require 'yasnippet)
(yas-global-mode 1)
;; let's define a function which initializes auto-complete-c-headers and gets called for c/c++ hooks
(defun my:ac-c-header-init ()
  (require 'auto-complete-c-headers)
  (add-to-list 'ac-sources 'ac-source-c-headers)
  (add-to-list 'achead:include-directories '"/usr/include/c++/6")
)
;; now let's call this function from c/c++ hooks
(add-hook 'c++-mode-hook 'my:ac-c-header-init)
(add-hook 'c-mode-hook 'my:ac-c-header-init)

;;C++ begin

;; == irony-mode ==
(use-package irony
  :ensure t
  :defer t
  :init
  (add-hook 'c++-mode-hook 'irony-mode)
  (add-hook 'c-mode-hook 'irony-mode)
  (add-hook 'objc-mode-hook 'irony-mode)
  :config
  ;; replace the `completion-at-point' and `complete-symbol' bindings in
  ;; irony-mode's buffers by irony-mode's function
  (defun my-irony-mode-hook ()
    (define-key irony-mode-map [remap completion-at-point]
      'irony-completion-at-point-async)
    (define-key irony-mode-map [remap complete-symbol]
      'irony-completion-at-point-async))
  (add-hook 'irony-mode-hook 'my-irony-mode-hook)
  (add-hook 'irony-mode-hook 'irony-cdb-autosetup-compile-options)
  )

(setq irony-additional-clang-options '("-std=c++11"))

;; == company-mode ==
(use-package company
  :ensure t
  :defer t
  :init (add-hook 'after-init-hook 'global-company-mode)
  :config
  (use-package company-irony :ensure t :defer t)
  (setq company-idle-delay              nil
    company-minimum-prefix-length   2
    company-show-numbers            t
    company-tooltip-limit           20
    company-dabbrev-downcase        nil
    company-backends                '((company-irony company-gtags))
    )
  :bind ("C-;" . company-complete-common)
  )

;;C++ end

(global-set-key (kbd "C-x C-b") 'ibuffer)

(setq column-number-mode t)

;;; cperl-mode is preferred to perl-mode                                        
;;; "Brevity is the soul of wit" <foo at acm.org>                               

(defalias 'perl-mode 'cperl-mode)

;; just spaces
(setq-default indent-tabs-mode t)


(add-hook 'cperl-mode-hook
  (lambda()
    (custom-set-variables
      '(cperl-close-paren-offset -4)
      '(cperl-continued-statement-offset 4)
      '(tab-width 4)
      '(cperl-indent-level 4)
      '(cperl-indent-parens-as-block t)
      '(cperl-tab-always-indent t)
)


))

;; Use 4 space indents via cperl mode
(custom-set-variables
  '(cperl-close-paren-offset -4)
  '(cperl-continued-statement-offset 4)
  '(tab-width 4)
  '(cperl-indent-level 4)
  '(cperl-indent-parens-as-block t)
  '(cperl-tab-always-indent t)
)


(global-set-key [f4] 'compile)


;;; neotree
(add-to-list 'load-path "/home/sergio/.emacs.d/neotree")
  (require 'neotree)
  (global-set-key [f8] 'neotree-toggle)

(setq neo-smart-open t)


;; Set up the Common Lisp environment
(add-to-list 'load-path "/usr/share/common-lisp/source/slime/")
(setq inferior-lisp-program "/usr/bin/sbcl")
(require 'slime)
(slime-setup)


;; Text and the such
;; Use colors to highlight commands, etc.
(global-font-lock-mode t) 
;; Disable the welcome message
(setq inhibit-startup-message t)
;; Format the title-bar to always include the buffer name
(setq frame-title-format "emacs – %b")
;; Display time
(setq display-time-24hr-format t) ;; 24-часовой временной формат в mode-line
(display-time-mode             t) ;; показывать часы в mode-line
;; Make the mouse wheel scroll Emacs
(mouse-wheel-mode t)
;; Always end a file with a newline
(setq require-final-newline t)
;; Stop emacs from arbitrarily adding lines to the end of a file when the
;; cursor is moved past the end of it:
(setq next-line-add-newlines nil)
;; Flash instead of that annoying bell
(setq visible-bell t)
;; Remove icons toolbar
(if (> emacs-major-version 20)
(tool-bar-mode -1))
;; Use y or n instead of yes or not
(fset 'yes-or-no-p 'y-or-n-p)


;;activate show paren
(show-paren-mode t)   
;(setq show-paren-style 'expression) ; подсвечивает блоки, но раздражает




(put 'set-goal-column 'disabled nil)
