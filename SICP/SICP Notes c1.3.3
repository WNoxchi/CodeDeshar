; SICP NOTES: Chapter 1.3.3 Procedures as General Methods
; 18-Dec-2015 19:25

(define (search f negpoint pospoint)
  (let ((midpoint (average negpoint pospoint)))
       (if (close-enough? negpoint pospoint)
           midpoint
           (let ((test-value (f midpoint)))
             (cond ((positive? test-value)
                    (search f negpoint midpoint))   ; why negpoint midpoint if testval = [+]?
                   ((negative? test-value)
                    (search f midpoint pospoint))
                   (else midpoint))))))
;
;root is neg if midpoint is positive; because the root makes it go to zero! math.

; Testing if the endpoints are close enough:

(define (close-enough? x y) (< (abs (- x y)) 0.001))

; Using search as is may give wrong answers, bc no way to ensure inputs are correctly [+] or [-]
; Therefore call <search> using <halfintervalmethod>, which checks to see which of the endpoints has
;   a negative function value, and which is positive; and calls <search> accordingly.
;   If function has same sign on two given points - the half-interval-method cant be used, so the proc signals an error.

(define (halfintervalmethod f a b)
  (let ((a-value (f a))
        (b-value (f b)))
    (cond ((and (negative? a-value) (positive? b-value))
           (search f a b))
          ((and (negative b-value) (positive? a-value))
           (search f b a))
          (else
           (error "Values are not of opposite sign" a b)))))
;
; Using halfinterval to approx Pi as the root between 2 and 4 of sinx=0:

(halfintervalmethod (sin 2.0 4.0)
;=> 3.14111328125

; Using halfinterval to search for the root of equation x^3 - 2x - 3 = 0 between 1 and 2:

(halfintervalmethod (lambda (x) (- (* x x x) (* x 2) 3))
                    1.0
                    2.0)
;=> 1.89306640625

; this is very simple; just use lambda to define the function, then specify parameters for halfinterval
;-----------------------------------------
;----Finding Fixed Points of Functions----
;-----------------------------------------

(define tolerance 0.00001)
(define (fixedpoint f halxara-guess)
  (define (close-enough? v1 v2)
    (< (abs (- v1 v2))
       tolerance))
  (define (try guess)
    (let ((next (f guess)))         ; let <next> be the function applied to guess
      (if (close-enough? guess next)
          next                      ; if close enough: return function. f(x)
          (try next))))             ; if not close enough: apply function again to itself. f(f(x))
  (try halxara-guess))

; Aldashna, can use this method to approx fixed point of cosine function:

(fixedpoint cos 1.0)
;=> 0.7390822985224023

; Also, can find a solution to equation: y = sin(y) + cos(y)

(fixedpoint (lambda (y) (+ (sin y) (cos y))) 1.0)         ; heh, I wrote that on my own.
;=> 1.2587315962971173

; Defining a square-root calculation as a fixed-point search:
(define (sqrt x)
  (fixedpoint (lambda (y) (/ x y))
              1.0))
;----> but this just oscillates about the answer & never converges
; Rewrite to map y --> avg(y, (x/y))  ----> that way we get closer each time, by restraining guess distance from y:
(define (sqrt x)
  (fixedpoint (lambda (y) (average y (/ x y)))
              1.0))



;-------------------------------------------------
; SICP 1.34    Start: 18-Dec-2015 15:33    Finish:  18-Dec-2015 15:39
;-------------------------------------------------
(define (square x) (* x x))

(define (f g) (g 2))

;(f square)
;=> 4
;(f (lambda (z) (* z (+ z 1))))
;=> 6

; What happens if we ask the interpreter to eval: (f f) ? Explain.
;-------------------------------------------------

; Wouldn't it do nothing because <<lambda>> is a proc defined 'on the fly'?
; Aha!
; (f g) calls (g 2)
; -> so (f f) calls (f 2) which calls (2 2). It's a recursive call.
; 2 isn't a proc, so error is reported.


;-------------------------------------------------
; SICP 1.35
;-------------------------------------------------
; show that ф is a fixed point of the trnsfn: x |-> 1 + 1/x
; compute ф by fixedpoint proc.

(define tolerance 0.00001)
(define (fixedpoint f halxara-guess)
  (define (close-enough? v1 v2)
    (< (abs (- v1 v2))
       tolerance))
  (define (try guess)
    (let ((next (f guess)))
      (if (close-enough? guess next)
          next
          (try next))))
  (try halxara-guess))
;-----------------------------
(define (Fib x)
  (fixedpoint (lambda (x) (+ 1 (/ 1 x)))
              1.0))
;-----------------------------
;----Testing:
(Fib 1)
;=> 1.6180327868852458
; fi is indeed a fixed point of x |-> 1 + 1/x
;-------------------------------------------------




;-------------------------------------------------
; SICP 1.36   Start:  18-Dec-2015 19:25   Finished: 18-Dec-2015 19:51
;-------------------------------------------------

(define tolerance 0.00001)
(define (fixedpoint f halxara-guess)
  (define (close-enough? v1 v2)
    (< (abs (- v1 v2))
       tolerance))
  (define (try guess)
    (let ((next (f guess)))
      (if (close-enough? guess next)
          next
          (try next))))
  (try halxara-guess))
;-----------------------------
(define (Fib x)
  (fixedpoint (lambda (x) (+ 1 (/ 1 x)))
              1.0))
;-----------------------------

(define (average x y) (/ (+ x y) 2))

(define tolerance 0.00001)
(define (fixedpoint f halxara-guess)
  (define (close-enough? v1 v2)
    (< (abs (- v1 v2))
       tolerance))
  (define (try guess)
    (display guess)       ; displaying the guess is really that simple
    (newline)
    (let ((next (f guess)))
      (if (close-enough? guess next)
          next
          (try next))))
  (try halxara-guess))

(define (xupx x)
  (fixedpoint (lambda (x) (/ (log 1000) (log x)))
              2.0))

;-----------------------------
;x^x = 1000
;fixedpoint of: x |-> Log(1000)/Log(x)

; Now rewriting fixedpoint using average damping:
; just average the input value of x with the computed value:

(fixedpoint (lambda (x) (average x (/ (log 1000) (log x))))
            2.0))
;
;
;
; It's a thing of beauty:
;-------------------------------------------------
(define (average x y) (/ (+ x y) 2))

(define tolerance 0.00001)
(define (fixedpoint f halxara-guess)
  (define (close-enough? v1 v2)
    (< (abs (- v1 v2))
       tolerance))
  (define (try guess)
    (display guess)       ; displaying the guess is really that simple
    (newline)
    (let ((next (f guess)))
      (if (close-enough? guess next)
          next
          (try next))))
  (try halxara-guess))
;-----------------------------
;(define (xupx x)
;  (fixedpoint (lambda (x) (/ (log 1000) (log x)))
;              2.0))
;-----------------------------

(display 'AVG-DAMPED:)
(newline)

(fixedpoint (lambda (x) (average x (/ (log 1000) (log x))))
            2.0)

(display 'UNDAMPED:)
(newline)

(fixedpoint (lambda (x) (/ (log 1000) (log x)))
              2.0)
;-------------------------------------------------
;----OUTPUT:
; AVG-DAMPNED:
; 2
;....[7 lines]....
; 4.5555465521473675
; UNDAMPED:
; 2
;....[33 lines]....
;=> 4.555532270803653
;-------------------------------------------------
