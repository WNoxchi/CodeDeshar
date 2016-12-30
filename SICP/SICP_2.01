; SICP_2.01
;-----------------------------------------------------------
; Define a better version of <make-rat> that handles both [+]] and [-]] arguments.
; <make-rat> should normalize the sign s.t. if the rational number is [+] both the
; numerator and denominator are [+], and if the rational number is [-], only the
; numerator is [-].
;-----------------------------------------------------------
; Completed:  24-Dec-2015 13:38


(define (gcd a b)
  (if (= b 0)
      a
      (gcd b (mod a b))))

;(define x (cons 1 2))

(define (makrat n d) (printrat(cons n d)))
(define (numer x) (car x))
(define (denom x) (cdr x))

(define (printrat x)
    (newline)
    (display (numer x))
    (display "/")
    (display (denom x))
    (newline))

(define (kerlomakrat numer denom)
  (cond ((and (< numer 0) (> denom 0))
              (makrat numer denom))
        ((and (> numer 0) (< denom 0))
              (makrat (* numer -1) (* denom -1)))
        ((and (< numer 0) (< numer 0))
              (makrat (* numer -1) (* denom -1)))
        ((and (> numer 0) (> denom 0))
              (makrat numer denom))
        ((and (= numer 0) (not (= denom 0)))
              (display "0"))
        (else (display "Yo WTF?" ) (newline)))
    (newline))


;-----------------------------------------------------------
; NOTES BELOW:
;-----------------------------------------------------------


(define (make-rat n d)
  (let ((g (gcd n d)))
    cons (/ n d) (/ d g)))

; (define x (cons 1 2)
; (car x)
; 1
; (cdr x)
; 2

; Another way to define the selectors and constructor:
(define make-rat cons)
(define numer car)
(define denom cdr)

(define (print-rat x)
  (newline)
  (display (numer x))
  (display "/")
  (display (denom x)))

;

(define x (cons 1 2))

(define (kerlomake-rat sign n d)
  (define (make-rat n d)
    (let (g (gcd n d)))
      (cons ((/ n g) (d g))))
  (cond ((= sign +) (make-rat n d))
        ((= sign -) (-(make-rat n d)))
        (else (error))))

;
; Defining GCD proc:

(define (gcd a b)
  (if (= b 0)
      a
      (gcd b (mod a b))))

; if only num or denom > 0 then (* -1 denom) = denom
; if both num &denom > 0 then (* -1 denom) = denom AND (* -1 numer) = number

logical cases:

- numer AND + denom:  (makrat n d)
+ numer AND - denom:  (makrat (* -1 n) (* -1 d))
- numer AND - denom:  (makrat (* -1 n) (* -1 d))
+ numer AND + denom:  (makrat n d)

;-*-mode:scheme;-*-
