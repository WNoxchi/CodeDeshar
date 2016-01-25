;-------------------------------------------------------------------------------
; SICP_2.23 / CS61A - Wayne H. Noxchi
;-------------------------------------------------------------------------------
; 3.07  define proc to make joint bank accounts - takes 3 args
;-------------------------------------------------------------------------------
; Start: 25-Jan-2016 18:06 --- 25-Jan-2016 18:23


;From: https://wqzhang.wordpress.com/2009/07/12/sicp-exercise-3-7/
(define (make-account balance password)
    ;(define (withdraw amount)
    ;    (if (>= balance amount)
    ;        (begin (set! balance (- balance amount))
    ;               balance)
    ;        "Insufficient funds"))
    ;(define (deposit amount)
    ;    (set! balance (+ balance amount))
    ;    balance)
    ;(define (display-error amount)
    ;    "Incorrect password")
    (define (mkjoint entrant-pass)
        (set! password-list (cons entrant-pass password-list))
        dispatch)
    (let ((password-list (list password)))
        (define (dispatch pass m)
            (if (memq? pass password-list) ; ohh, member equals, testing if the lists are equal
                (cond ((eq? m 'withdraw) withdraw)
                      ((eq? m 'deposit) deposit)
                      ((eq? m 'make-joint)
                      else (error "Unkown request: MAKE-ACCOUNT"
                                  m)))
                display-error)
        dispatch))
(define (make-joint account account-pass entrant-pass)
    ((account account-pass 'make-joint) entrant-pass))  ;что?

; Or: http://community.schemewiki.org/?sicp-ex-3.7
(define (make-joint account old-pass new-pass)
  (and (number? ((account old-pass 'withdraw) 0))
       (lambda (pass msg)
         (if (eq? pass new-pass)
             (account old-pass msg)
             (account 'bad-pass 'foo))))) ;increment bad-passwords
; Or also: https://wizardbook.wordpress.com/2010/12/14/exercise-3-7/

;-------------------------------------------------------------------------------
; SICP_2.23 / CS61A - Wayne H. Noxchi
;-------------------------------------------------------------------------------
; 3.04
;-------------------------------------------------------------------------------
; Start: 25-Jan-2016 17:40 --- 25-Jan-2016 17:57

;Correction:(https://wqzhang.wordpress.com/2009/07/10/sicp-exercise-3-4/)

(define (make-account balance password)
    (let ((incorrect-access-count 0))   ; so the let is how he's initializing access count to zero
    ;    (define (withdraw amount)
    ;        (if (>= balance amount)
    ;            (begin (set! balance (- balance amount))
    ;                   balance)
    ;            "Insufficient funds"))
    ;    (define (deposit amount)
    ;        (set! balance (+ balance amount))
    ;        balance)
        (define (call-the-cops amount)
            (display "call the cops"))
        ;(define (display-error amount)
        ;    "Incorrect password")
        (define (dispatch p m)
            (if (eq? pass password)
                (begin (set! incorrect-access-count 0)  ; set! is how he resets access count to zero
                       (cond ((eq? m 'withdraw) withdraw)
                             ((eq? m 'deposit) deposit)
                             (else (error "Unknown request -- MAKE-ACCOUNT"
                                          m))))
                (begin (set! incorrect-access-count     ; set! alternatively increments it by 1
                             (+ 1 incorrect-access-count))
                       (if (> incorrect-access-count 7)
                           call-the-cops
                           display-error))))
        dispatch))

; What I had by 25-Jan-2016 17:49:
(define (make-account balance password access-count)
    (define (withdraw amount)
        reset-access
        (if (>= balance amount)
            (begin (set! balance (- balance amount))
                   balance)
            "Insufficient funds"))
    (define (deposit amount)
        reset-access
        (set! balance (+ balance amount))
        balance)
    (define (display-error amount access-count)
        (+ access-count 1)
        "Incorrect password"
        (if (>= access-count 7) call-the-cops)
    (define (reset-access access-count m)
        set! access-count 0)
    (define (call-the-cops m)
        "weee-wooo woop woop dats da sound of da police!")
    ;(define (dispatch pass m)
    ;    (if (eq? pass password)
    ;        (cond ((eq? m 'withdraw) withdraw)
    ;              ((eq? m 'deposit) deposit)
    ;              else (error "Unkown request: MAKE-ACCOUNT"
    ;                          m)))
    ;        display-error)
    ;dispatch)

;-------------------------------------------------------------------------------
; SICP_2.23 / CS61A - Wayne H. Noxchi
;-------------------------------------------------------------------------------
; 3.03  add password feature to bank account proc
;-------------------------------------------------------------------------------
; Start: 25-Jan-2016 15:12 | Xan: < 1 saht

;Correction:(check: https://wqzhang.wordpress.com/2009/07/10/sicp-exercise-3-3/)

(define (make-account balance password)     ; ok so simple, just put in a password parameter
    (define (withdraw amount)               ; most of rest as normal
        (if (>= balance amount)
            (begin (set! balance (- balance amount))
                   balance)
            "Insufficient funds"))
    (define (deposit amount)
        (set! balance (+ balance amount))
        balance)
    ; what we do here is make a password-error proc and build the pass check into dispatch
    (define (display-error amount)
        "Incorrect password")   ; what's confusing is why does this need to take amount as an arg?
    (define (dispatch pass m)
        (if (eq? pass password)
            (cond ((eq? m 'withdraw) withdraw)
                  ((eq? m 'deposit) deposit)
                  else (error "Unkown request: MAKE-ACCOUNT"
                              m)))
            display-error)
    dispatch)

;Original Try by 25-Jan-2016 15:22:

;(define (passcheck n)
;    (if ((eq? n password) dispatch)
;        (error "Incorrect password")))

(define (make-account balance)
    ;(define (withdraw amount)
    ;    (if (>= balance amount)
    ;        (begin (set! balance (- balance amount))
    ;               balance)
    ;        "Insufficient funds"))
    ;(define (deposit amount)
    ;    (set! balance (+ balance amount))
    ;    balance)
    ;(define (dispatch m)
    ;    (cond ((eq? m 'withdraw) withdraw)
    ;          ((eq? m 'deposit) deposit)
    ;          (else (error "Unkown request: MAKE-ACCOUNT"
    ;                       m))))
    (define (passcheck n)
        (if ((eq? n password) dispatch)
            (error "Incorrect password")))
    passcheck)


;-------------------------------------------------------------------------------
; SICP_2.23 / CS61A - Wayne H. Noxchi
;-------------------------------------------------------------------------------
; 3.08  def proc s.t. (+ (f 0) (f 1)) returns 0 if args to + are eval l-r, but
;       1 if eval r-l
;-------------------------------------------------------------------------------
; Start: 25-Jan-2016 18:24 --- 25-Jan-2016 18:30

; I have no idea what they're talking about or even how to write this.
; I know f needs a variable inside s.t. if you give it 0 first it's zero; but
; dunno how.

;https://wqzhang.wordpress.com/2009/07/13/sicp-exercise-3-8/
;(define f
;  (let ((state 0))
;    (define (switch-state x)
;      (let ((old-state state))
;        (set! state (+ x state))
;        old-state))
;    switch-state))

;http://community.schemewiki.org/?sicp-ex-3.8
;    (define (g y)
;       (define (f x)
;        (let ((z y))
;           (set! y x)
;           z))
;       f)
;     (define f (g 0))
