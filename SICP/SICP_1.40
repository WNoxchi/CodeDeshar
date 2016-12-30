; SICP Exercise 1.40    |   18-Dec-2015 23:01
; define a proc <cubic> that can be used with <newtons-method> in expressions of the form:
;   (newtons-method (cubic a b c) 1)  to approximate zeros of cubic functions of form:  f(x) = x^3 + ax^2 + bx + c
;   Note: that is simplification of standard eqn: f(x) = ax^3 + bx^2 + cx + d (trsfm by div by leading coeff)

; Heavy leaning on: http://www.billthelizard.com/2010/08/sicp-140-zeros-of-cubic-function.html
; I'm forcing myself through tonight..

;----<fixed-point> from s1.3.3:

; support procedures from earlier in the section

(define tolerance 0.00001)
(define (fixed-point f first-guess)
  (define (close-enough? v1 v2)
    (< (abs (- v1 v2)) tolerance))
  (define (try guess)
    (let ((next (f guess)))
      (if (close-enough? guess next)
          next
          (try next))))
  (try first-guess))

(define dx 0.00001)
(define (deriv g)
  (lambda (x)
    (/ (- (g (+ x dx)) (g x))
       dx)))

;----<newtons-method> from s1.3.4:

(define (newton-transform g)
  (lambda (x)
    (- x (/ (g x) ((deriv g) x)))))

(define (newtons-method g guess)
  (fixed-point (newton-transform g) guess))
;
; <newtons-method> proc takes as args a proc that computes the function for which we want to find a zero, along w an intial guess.
; => <cubic> proc must return a proc.
;   The returned proc should take one parameter and compute the value of the cubic function up top.
;   Combining it w/ <newtons-method> will compute zeroes of that function.

; this is the definition of cubic that I was having difficulty figuring out.
; oh... no shit...

(define (cubic a b c)
  (lambda (x)
    (+ (* x x x)
       (* a x x)
       (* b x)
       c)))
;
;> (newtons-method (cubic 3 -2.4 6) 1)
;-3.981336651146034

;^ check with online Cubic Function Explorer (& to get initial input values)
;-*-mode:scheme;-*-
