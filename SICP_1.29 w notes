: SICP_1.29       >> Total Time: ~ 4-5 hours | 17 Ogoi 2015
; Use Simpson's Formula to write an integration procedure:

(define (SIntegral f a b n)
  (define h (/ (- b a) n))
  (define (inc x) (+ x 1))
  (define (y k)
    (f (+ a (* k h))))
  (define (term k)
    (* (cond ((or (= k 0) (= k n)) 1)
             ((odd? k) 4)
             ((even? k) 2))
       (y k)))
  (* (/ h 3) (sum term 0 inc n)))
(define (cube x) (* x x x))
(define (sum term a next b)
  (if (> a b)
      0
      (+ (term a)
         (sum term (next a) next b))))

; NOTE: order of the conditionals matters

;(define (even? x) (= (mod x 2) 0))
;(define (odd? x) (= (mod (+ x 1) x) 0)))

;-------------------------------------------------
;>>> Notes on Summation:
;vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

; template for summing

(define (<<name>> a b)
  (if (> a b)
      0
      (+ (<<term>> a)
         (<<name>> (<<next>> a) b))))

; general formula for summation:

(define (sum term a next b)
  (if (> a b)
      0
      (+ (term a)
         (sum term (next a) next b))))

; summing cubes:

(define (inc n) (+ n 1))
(define (sumcubes a b)
  (sum cube a inc b))

; sum integers with aid of identity proc

(define (identity x) x)
(define (sum-integers a b)
  (sum identity a inc b))

; approximate pi:

(define (pi-sum a b)
  (define (pi-term x)
    (/ 1.0 (* x (+ x 2))))
  (define (pi-next x)
    (+ x 4))
  (sum pi-term a pi-next b))

;>>>(* 8 (pi-sum 1 1000))
;=> 3.139592655589783

; definite integral of a function f between limits a & b approximated (for small vals dx):

(define (integral f a b dx)
  (define (add-dx x)
    (+ x dx))
  (* (sum f (+ a (/ dx 2.0)) add-dx b)
     dx))

;

;------------------------------------------------
; Second try attempts (with reference)
; reference: http://www.billthelizard.com/2010/04/sicp-exercise-129-integration-using.html
;------------------------------------------------

(define (sum term a next b)
  (if (> a b)
      0
      (+ (term a)
         (sum term (next a) next b))))

(define (inc n) (+ n 1))
;---------------------------------------

(define (even? x) (= (mod x 2)))
(define (cube x) (* x x x))

(define (h a b n)
  (/ (- b a) n))

(define (SEQy f a b k n)
  (f (+ a (* k (/ (- b a) n)))))

(define (SEQk k n f a b)
  (cond ((= k n) (+ (SEQk (- k 1) n f a b) (SEQy f a b k n)))
        ((even? k) (+ (SEQk (- k 1) n f a b) (* (SEQy f a b k n) 2)))
        ((not (even? k)) (+ (SEQk (- k 1) n f a b) (* (SEQy f a b k n) 4)))
        (else (SEQy f a b 0 n))
  ))

(define (SIntegral f a b n)   ; function start end resolution
  (* (/ (h a b n) 3) (SEQk n n f a b))
)
;---------------------------------------
; SIntegral formula is sum of a series; so using sum proc:

(define SIntegral f a b n)
  (/ (* h (sum term 0 inc n)) 3)

(define h (/ (- b a) n))    ; oh, so that's how you define a variable...

(define (inc x) (+ x 1))    ; going from one term of the series to the next is just adding by one in this formula

; Defining the function for computing y_k:
(define (y k)
  (f (+ a (* k h))))

; Defining the rule for computing coeff of terms:
; Coeff = 1 for 0-algha & n-algha terms; Coeff = 2 for odd, = 4 for even
; Multiply coeff by y_k to get k-algha-term.
(define (term k)
  (* (cond ((odd? k) 4)
           ((even? k) 2)
           ((or (= k 0) (= k n)) 1))
     (y k)))

;--------- Putting it together:

(define (SIntegral f a b n)
  (* (/ h 3) (sum term 0 inc n)))

(define h (/ (- b a) n))
(define (inc x) (+ x 1))

(define (y k)
  (f (+ a (* k h))))

(define (term k)
  (* (cond ((even? k) 2)
           ((odd? k) 4)
           ((or (= k 0) (= k n)) 1))
     (y k)))

(define (even? x) (= (mod x 2) 0))
(define (odd? x) (= (mod (+ x 1) x) 0))

(define (sum term a next b)
  (if (> a b)
      0
      (+ (term a)
         (sum term (next a) next b))))

;-------------------------------------------------
; First try attempts before going to reference, below:
;------------------------------------------------

(define (cube x) (* x x x))
;(define (h b a n)
;  (/ (- b a) n))

; Checks: h definition works


(define (SIntegral f a b n)   ; function start end resolution
  (* (/ h 3) (SEQk n n))

; SEqn:

(define (SEQk k n)
  (cond ((= k n) (+ (SEQy f a k h) (SEQk (- k 1) n)) )
        ((even? k) (+ (SEQk (- 1 k) n) (* (SEQy f a k h) 2)))
        ((not (even? k)) (+ (SEQk (- 1 k) n) (* (SEQy f a k h) 4)))
        ((= k 0) (SEQy f a 0 h))))
)

(define (SEQy f a k h)
  (f (+ a (* k h))))

; question is gonna be how do I handle the h?

; Putting it all together below:

(define (SIntegral f a b n)   ; function start end resolution
  (define (h a b n)
    (/ (- b a) n))
  (define (SEQk k n)
    (cond ((= k n) (+ (SEQy f a k h) (SEQk (- k 1) n)) )
          ((even? k) (+ (SEQk (- 1 k) n) (* (SEQy f a k h) 2)))
          ((not (even? k)) (+ (SEQk (- 1 k) n) (* (SEQy f a k h) 4)))
          ((= k 0) (SEQy f a 0 h))
          (else (#f)))
  )
  (define (SEQy f a k h)
    (f (+ a (* k h))))
  (* (/ (h a b n) 3) (SEQk n n))
)

(define (even? x) (= (mod x 2)))
(define (cube x) (* x x x))

;----------------------------
; Debugging self-talk:

(define (SIntegral f a b n)
  (* (/ (h a b n) 3) (SEQk n n))

; h confirmed working.
; do I need to explicitly input args to h?
; yes. just defining function h does not make it a variable
; Now it works. Args must be input when calling a function (duh.).

(define (h a b n)
  (/ (- b a) n))

; Probably have same input args issue with SEQk and SEQy:
; Does SEQy work?
; What about subst. (h a b n) for every h when calling SEQy?
; --> SEQy will just input the result of (h a b n) as an arg, right?

;----------------------------
; Version 2:
;----------------------------

(define (SIntegral f a b n)   ; function start end resolution
  (define (h a b n)
    (/ (- b a) n))
  (define (SEQk k n)
    (cond ((= k n) (+ (SEQy f a k (h a b n)) (SEQk (- k 1) n)) )
          ((even? k) (+ (SEQk (- 1 k) n) (* (SEQy f a k (h a b n)) 2)))
          ((not (even? k)) (+ (SEQk (- 1 k) n) (* (SEQy f a k (h a b n)) 4)))
          ((= k 0) (SEQy f a 0 (h a b n)))
          (else (#f)))
  )
  (define (SEQy f a k h)
    (f (+ a (* k h))))
  (* (/ (h a b n) 3) (SEQk n n))
)

(define (even? x) (= (mod x 2)))
(define (cube x) (* x x x))

;----------------------------
; More debugging:

(define (SIntegral f a b n)   ; function start end resolution
  (* (/ (h a b n) 3) (SEQk n n))
)

(define (SEQk k n)
  (cond ((= k n) (+ (SEQy f a k (h a b n)) (SEQk (- k 1) n)) )
        ((even? k) (+ (SEQk (- 1 k) n) (* (SEQy f a k (h a b n)) 2)))
        ((not (even? k)) (+ (SEQk (- 1 k) n) (* (SEQy f a k (h a b n)) 4)))
        ((= k 0) (SEQy f a 0 (h a b n)))
        (else (#f)))
)

(define (SEQy f a k h)
  (f (+ a (* k h))))

(define (h a b n)
  (/ (- b a) n))

;------------------------------------------------
; Need to fix SEQk
;
; SEQk wants k and n.
; if k = n, then call SEQy + (SEQk k-1 n)
; if k even? then call 2*SEQy + (SEQk k-1 n)
; if k odd, then call 4*SEQy + (SEQk k-1 n)
; else: k = 0, call SEQy

; would I fix the arg# problem by adding the args SEQy needs into SEQk?

(define (SEQk k n f a b)
  (cond ((= k n) (+ (SEQk (- k 1) n f a b) (SEQy f a k h)))
        ((even? k) (+ (SEQk (- k 1) n f a b) (* (SEQy f a k h) 2)))
        ((not (even? k)) (+ (SEQk (- k 1) n f a b) (* (SEQy f a k h) 4))) ; may need to change h to (h a b n)  -- dits ma de
        (else (SEQy f a 0 h))
  )
)

;-----------------------------
; Even more debugging:

(define (SEQk k n f a b)
  (cond ((= k n) (+ (SEQk (- k 1) n f a b) (SEQy f a k h)))
        ((even? k) (+ (SEQk (- k 1) n f a b) (* (SEQy f a k h) 2)))
        ((not (even? k)) (+ (SEQk (- k 1) n f a b) (* (SEQy f a k h) 4)))
        (else (SEQy f a 0 h))
  )
)

(define (SEQy f a k h)
  (f (+ a (* k h))))

(define (h a b n)
  (/ (- b a) n))

(define (SIntegral f a b n)   ; function start end resolution
  (* (/ (h a b n) 3) (SEQk n n f a b))
)

; I could just modify the internal math of SEQy; thus no longer needing a clunky (h a b n) call..
;  just put the damn habn call inside SEQy.. you already defined it anyway.


(define (SEQy f a k n)
  (f (+ a (* k (h a b n)))))

;   now make sure to include n in the SEQy calls in SEQk; and you should be good.

(define (SEQk k n f a b)
  (cond ((= k n) (+ (SEQk (- k 1) n f a b) (SEQy f a k n)))
        ((even? k) (+ (SEQk (- k 1) n f a b) (* (SEQy f a k n) 2)))
        ((not (even? k)) (+ (SEQk (- k 1) n f a b) (* (SEQy f a k n) 4)))
        (else (SEQy f a 0 n))
  )
)

;---------------------------------------
; End of my blind attempt; now reading SICP book; and etc for pointers...

(define (even? x) (= (mod x 2)))
(define (cube x) (* x x x))

(define (h a b n)
  (/ (- b a) n))

(define (SEQy f a b k n)
  (f (+ a (* k (/ (- b a) n)))))

(define (SEQk k n f a b)
  (cond ((= k n) (+ (SEQk (- k 1) n f a b) (SEQy f a b k n)))
        ((even? k) (+ (SEQk (- k 1) n f a b) (* (SEQy f a b k n) 2)))
        ((not (even? k)) (+ (SEQk (- k 1) n f a b) (* (SEQy f a b k n) 4)))
        (else (SEQy f a b 0 n))
  ))

(define (SIntegral f a b n)   ; function start end resolution
  (* (/ (h a b n) 3) (SEQk n n f a b))
)

;---------------------------------------
;---------------------------------------
