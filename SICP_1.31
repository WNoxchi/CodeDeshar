; SICP_1.31   Start: 17-Dec-2015 23:22
;             Finish: 18-Dec-2015 00:10
;
; A:  The sum proc is the simplest of similar abstractions that can be captured as higher order procedures.
;   Write an analogous proc called <<product>> that returns product of values of a function at points over a given range.
;   Show how to determine <<factorial>> in terms of product.
;   Also use <product> to compute approxs to pi using formula:
;       (pi/4) = (2*4*4*6*6*...)/(3*3*5*5*7*...)
;
; B:  Write Recursive & Iterative versions.

;Product:

(define (product-recr term a next b)
  (if (> a b)
      1                 ; * by 1, instead of + 0 for <sum>
      (* (term a)
         (product-recr term (next a) next b))))

(define (product-iter term a next b)
  (define (iter a result)
    (if (> a b)
        result
        (iter (next a) (* (term a) result))))
  (iter a 1))

;-----------------------------
; Implementing <Fac> in terms of <product> using <identity> and <inc>:

(define (identity x) x)
(define (inc x) (+ x 1))
(define (Fac x)
  (product identity 1 inc x))   ; <identity> = term, 1 = a, <inc> = next, x = b

; remember to remove the -suffix from <product> definition in order to use this.
;-----------------------------
; Approximating Pi: (Wallis Formula)

(define (WalPi x)
  (define (walterm n)
    (/ (* 4.0 (square n)) (- 1 (* 4.0 (square n)))))
  (* 2.0 (product walterm 1 inc x)))

;-----------------------------
; First go-thru on Factorial:

; Factorial: (Fac a b) = (+ (* b a) (* b (- a 1))

(define (Fac-recur b a)   ; b = lakxara/лакхара/ლაკხარა a = laxara/лахара/ლახარა -- counting down from b to a
  (if (< b a)
      0
      (* (Fac-recur (- b 1) a) (* b a))))

; using product-recr form:

(define (Fac-recur a b)   ; ; b = lakxara/лакхара/ლაკხარა a = laxara/лахара/ლახარა -- counting up from a to b
  (if (> a b)
      0
      (* (Fac-recur (+ a 1) b) (* a b))))

;-----------------------------
Iter Sum:

(define (sum term a next b)
  (define (iter a result)
    (if (> a b)
        result
        (iter (next a) (+ (term a) result))))
  (iter a 0))

Recur Sum:

(define (sum term a next b)
  (if (> a b)
      0
      (+ (term a)
         (sum term (next a) next b))))
;---------------------------------------
; Checked w: http://www.billthelizard.com/2010/05/sicp-exercise-131-product-of-series.html
; I did a lot better, and only needed to use the ref minimally to 'round the edges' & check
;-*- mode:scheme;-*-
