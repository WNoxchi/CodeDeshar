Structure and Interpretation of Computer Programs
Aldashna 1.8

Define a cube root procedure using Newton's method for finding cube roots: (x/y^2 + 2y)/3

Structure: what will need what:
> creating cube-root procedure
  ->  def cube-root
    ->  def cube-root-iteration
      ->  def good-enough? (check method)
        ->  def improve
          ->  def cube
            ->  def square

;written in Scheme

; we first define what squaring & cubing are. (absolute value is predefined)

(define (cube x)
  (* x x x))
(define (square x)
  (* x x))

; now use Newton's method to create the improvement proc

(define (improve guess x)
  (/ (+ (/ x (square guess)) (* 2 guess)) 3))
  
; Now that we have a way to improve our guess we need a way to check if it's close enough
; We check if the absolute value of our guess cubed minus x is less than 0.001, our chosen margin of error.

(define (good-enough? guess x)
  (< (abs (- (cube guess) x))
    0.001))

; With a checking proc defined, we now need to implement in a procedure that'll iterate, improving
;   our guess until it's good enough.

(define (cube-root-iter guess x)
  (if (good-enough? guess x)
      guess
      (cube-root-iter (improve guess x)
                      x)))

; How the iteration procedure works:
;   If the good-enough proc returns True (#t), return the guess. We are finished.
;   If it returns False (#f), run the alternative:
;     the iter proc applied to the improved guess, and repeat until a value of #t is achieved.
;     This is a recursive call using the iter proc to iterate through improve procedures, which
;     in turn use good-enough? procs to determine when to stop (otherwise you'd get an infinite loop).

; Finally, we define procedure 'cube-root' which supplies 'cube-root-iter' with an initial guess to start.

(define (cube-root x)
  (cube-root-iter 1.0 x))


;
-*- mode: scheme;-*-
