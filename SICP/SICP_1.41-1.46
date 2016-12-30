; SICP 1.41   Start: 19-Dec-2015 10:14  | Finish: 19-Dec-2015 10:20
;-------------------------------------------------

; Define a procedure <double>. that takes a procedure of one argument as an argument and returns a procedure that applies
;   the original procedure twice.

;(define (twice proc x) (proc (proc x)))        ; 'double' = 'twice'

(define (twice f)
  (lambda (x) (f (f x))))

;>(((double (double double)) inc) 5)
;=> 21
;-------------------------------------------------
; SICP 1.42   Start:  19-Dec-2015 10:25 | Finish: 19-Dec-2015 10:35
;-------------------------------------------------
; Define a procedure <compose> which implements the composition of two functions:

((compose square inc) x)
;-> should return:
;=> (square (+ x 1))
; so: ((compose square inc) 6) returns: 49

(define (compose f g)
  (lambda (x) (f (g x))))

; Reference: http://www.billthelizard.com/2010/08/sicp-141-143-procedures-as-returned.html
;-------------------------------------------------
; SICP 1.43   Start:  19-Dec-2015 10:35 | Finish: 19-Dec-2015 11:13
;-------------------------------------------------
; Write a proc that takes as inputs a proc tht computes f and a [+] int n and returns the proc
;   tht computes the n-th repeated application of f. Proc should be usable as such:
;> ((repeated square 2) 5)      ; this means: square 5, 2 times. -ish
;=> 625

(define (compose f g)
  (lambda (x) (f (g x))))

(define (repeated f x)
  (if (= x 1)
      f
      (compose f (repeated f (- x 1)))))

; I was confused on why the 5 is outside, amma xjinca so kxeta.
;   The way Lisp/Scheme works is (function) (x) or (operator) (operand)
;   That means: everything inside the parentheses gets applied to the 5 just outside.
;   That's why it's important that the <repeated> proc takes in a proc and outputs a proc, because it's result
;     is applied to the number just outside. Essentially:
; ((repeated square 2) 5)
;  ------------------  -
;          ^           ^
;   (apply this)   (to that)
;
; It looks more obvious this way:
;
;   ( (repeated square 2) (5) )
;
; Wow, I easily just spent an hour working on SICP exercises.... no wonder my coffee keeps mysteriously getting cold...

;-------------------------------------------------
; SICP 1.44   Start: 19-Dec-2015 11:21  | Finish: 19-Dec-2015 12:11
;-------------------------------------------------
; Write a proc <smooth> that takes as input a proc that computes f and returns a proc that computes the smoothed f.
; f function yu, a dx jim terah yu a --- then smoothed f at x is average of f(x-dx), f(x), and f(x+dx)


(define smooth f
  (define (average f x)
    (/ (+ (f x) (f (+ x dx)) (f (- x dx))) 3))
  (average f x)

; but the input and output must both be procs, so this needs rewriting:

(define dx 0.00001)

(define (averagef f x)
  (/ (+ (f x) (f (+ x dx)) (f (- x dx))) 3))

; spec multip lambdas in average?

(define (cube x) (* x x x))
(define dx 0.00001)

(define (smooth f)
  (define (average f)
    (/ (+
        (lambda (x) (f x))
        (lambda (x) (f (+ x dx)))
        (lambda (x) (f (- x dx)))
        ) 3)
    )
    (average f))

((smooth cube) 5)

;---->  OK, my lambda definitions aren't working... I think.. getting #<Closure> error, so the number isn't being passed into the proc as an argument...
; aaaahaaaaaaa!... OK...
; so I was close, but off the mark.
;  (using reference now: http://www.billthelizard.com/2010/08/sicp-144-smoothing-function.html)

(define (smooth f dx)
  (lambda (x)
    (/ (+ (f x)
          (f (+ x dx))
          (f (- x dx)))
       3)))

; as I thought.. defining a subproc <average> was unnecessary.
; ok, and he's letting user spec dx instead of defining it.. okay...
; so... lambda is only done once.. hmm... looks like that's the one place where I went wrong (functionally)
; Wait.. doesn't that make sense? You have ... ah. Yes.
;   Because in SICP 1.41, we used only 1 lambda to specify a polynomial...
;   Oh, that's because there was 1 variable, x, being acted upon... same goes here...

(define (cube x) (* x x x))
(define dx 0.00001)

(define (smooth f)
    (lambda (x)
        (/ (+
           (f x)
           (f (+ x dx))
           (f (- x dx)))
        3)))


;   OK. Rewrote it blank and got it working. Now to do an n-fold smoothing function using <repeated>:

; same def of <repeated> from 1.43:

(define (repeated f x)
  (if (= x 1)
      f
      (compose f (repeated f (- x 1)))))

(define (compose f g)
  (lambda (x) (f (g x))))     ; wrote that from my head. Life's little victories.. :)

(define (nfold-smooth f n)
  (repeated (smooth f) n))

; Usage:

((nfold-smooth cube 3) 5)
;--> smooth the cube of 5, 3 times.

; It works! ...although I don't think you should try to smooth a cubic function... holy shit that gets big....
; Perhaps an oscillating function like the trig functions... that would make sense since smoothing is used in Signal Processing.... Yup.
; Code can be rewritten to have dx as a specified input. In that case use the first <smooth> proc, and this version of <nfold-smooth>:

(define (nfold-smooth f dx n)
  (repeated (smooth f dx) n))

;   Wow this exercise took me 50 minutes...

;-------------------------------------------------
; SICP 1.45   Start:  19-Dec-2015 12:19 | Finish:   19-Dec-2015 13:23
;-------------------------------------------------

(define (cube x) (* x x x))

(define tolerance 0.00001)
(define (fixedpoint f halxara-guess)
  (define (close-enough? v1 v2)
    (< (abs (- v1 v2)) tolerance))
  (define (try guess)
    (let ((next (f guess)))
      (if (close-enough? guess next)
          next
          (try next))))
  (try halxara-guess))

(define (average x y)
  (/ (+ x y) 2.0))
(define (averagedamp f)
  (lambda (x) (average x (f x))))

;----TESTING:

(define (dialgh-root x)
  (fixedpoint (averagedamp (averagedamp (lambda (y) (/ x (cube y)))))
              1.0))

(define (pxialgh-root x)
  (fixedpoint (averagedamp (averagedamp (lambda (y) (/ x (* y y y y)))))
              1.0))

(define (yalxalgh-root x)
  (fixedpoint (averagedamp (averagedamp (lambda (y) (/ x (* y y y y y)))))
              1.0))

(define (varhalgh-root x)
  (fixedpoint (averagedamp (averagedamp (lambda (y) (/ x (* y y y y y y)))))
              1.0))

;   they all work.. it seems like average damping twice does it?
;   Am I even testin gthis right?

; Using the <expt> and <repeated> procs to make things cleaner:

(define (nth-root x n)
  (fixedpoint ((repeated averagedamp 2)          ; oh shit, now I see why it's so imprtant that <repeated> returns a proc, so it can work on something outside itself
                (lambda (y) (/ x (expt y (- n 1)))))
              1.0))

; I'm starting to lean on http://www.billthelizard.com/2010/08/sicp-145-computing-nth-roots.html more than I'd like, but still..
; 2 damps fail at n = 8. 1 damp fails at n = 4
; 3 damps fail at n = 16. So it's a 4(x^2) pattern.
; That's easy enough to fix by specifying a lambda right?

(define (log2 x)
  (/ (log x) (log 2)))

(define (nth-root x n)
  (fixedpoint ((repeated averagedamp (floor (log2 n)))
                (lambda (y) (/ x (expt y (- n 1)))))
              1.0))

; It wooooorks!
;note:
; n:  4 8 16  ... 32  64  ...
; d:  1 2  3  ...  4   5  ...
; Above: at what values of n do values of d (# of avgdamps) fail.

; So: take Log2(n), floor the result (so you get an int not a float), and you have the appropriate d (+1 above failure point).
; Scheme & Lisp only do ln, therefore: convert to log2 by: log2 = (ln x)/(ln 2)   {= (log(x))/(log(x)) }

;The full working proc below:
;-------------------------------------------------

(define (cube x) (* x x x))

(define tolerance 0.00001)
(define (fixedpoint f halxara-guess)
  (define (close-enough? v1 v2)
    (< (abs (- v1 v2)) tolerance))
  (define (try guess)
    (let ((next (f guess)))
      (if (close-enough? guess next)
          next
          (try next))))
  (try halxara-guess))

(define (average x y)
  (/ (+ x y) 2.0))
(define (averagedamp f)
  (lambda (x) (average x (f x))))

(define (compose f g)
  (lambda (x) (f (g x))))

(define (repeated f x)
  (if (= x 1)
      f
      (compose f (repeated f (- x 1)))))

(define (log2 x)
  (/ (log x) (log 2)))

(define (nth-root x n)
  (fixedpoint ((repeated averagedamp (floor (log2 n)))
                (lambda (y) (/ x (expt y (- n 1)))))
              1.0))

;-------------------------------------------------
; and this exercise took 64 minutes...
;-------------------------------------------------
; SICP 1.46   Start:  19-Dec-2015 13:38 | Finish: 19-Dec-2015 13:50
;-------------------------------------------------

; sqrt procedure and sub-procedures from SICP 1.1.7

; Looking at similarities & differences of the procs mentioned in the exercise.

(define (sqrt x)
   (sqrt-iter 1.0 x))

(define (sqrt-iter guess x)
   (if (good-enough? guess x)
       guess
       (sqrt-iter (improve guess x)
                  x)))

(define (improve guess x)
   (average guess (/ x guess)))

(define (average x y)
   (/ (+ x y) 2))

(define (good-enough? guess x)
 (< (abs (- (square guess) x)) 0.001))

(define (square x) (* x x))


; fixed-point procedure from SICP 1.3.3

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
;
; Both <sqrt> and <fixed-point> procs use helper functions to do the iteration: <sqrt-iter> & <try>
; We'll use a helper function <iterative-improve> and it'll be returned by the proc.
; Lambda can't be used bc we need to define a proc in order for it to call itself recursively.

(define (iterative-improve good-enough? improve)
   (define (iter-imp guess)
     (if (good-enough? guess)
         guess
         (iter-imp (improve guess))))
   iter-imp)
;
; Define the proc <iter-imp> that takes a guess as its parameter. If guess good enough --> return guess
;   If not: call <iter-imp> again with a new guess gotten by calling <improve> that was passed as the 2nd parameter to <iterative-improve>

; Redefining <sqrt> in terms of <iterative-improve>
; <good-enough?> & <imrpove> from the <sqrt> proc are recast as lambdas:

(define (sqrt x)
   ((iterative-improve (lambda (guess)
                         (< (abs (- (square guess) x))
                            0.001))
                       (lambda (guess)
                         (average guess (/ x guess))))
   1.0))

; Redefining <fixed-point> in terms of <iterative-improve>:

(define (fixed-point f first-guess)
   ((iterative-improve (lambda (guess)
                         (< (abs (- (f guess) guess))
                            0.00001))
                       (lambda (guess)
                         (f guess)))
    first-guess))

; <good-enough> procs in <sqrt> & <fixed-point> nearly identical.
; <improve> for <fixed-point> is simpler bc: to improve a guess when finding a fixed point -- you just need to apply function whose
;   fixed point you're trying to find, to the guess.

; Testing, using proc defined in SICP 1.35 to det golden ration ф:

;> (fixed-point (lambda (x) (+ 1 (/ 1 x))) 2.0)
;=>1.6180371352785146

; Using http://www.billthelizard.com/2010/08/sicp-146-iterative-improvement.html to basically take notes for this exercise.
;-------------------------------------------------
;-*- mode:scheme;-*-
