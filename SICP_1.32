; SICP_1.32   |   18-Dec-2015 14:34
; Show that <sum> and <product> are special cases of a general notion called <accumulate> that combines
;   a collection of terms, using some general accumulation function:
; <combiner> takes 2 args and specifies how the current term is to be combined w the accumulation of preceding terms.

; (accumulate combiner null-value term a next b)

; Iterative Accumulate:
(define (accumulate-iter combiner null-value term a next b)
  (define (iter a result)
    (if (> a b)
        result
        (iter (next a) (combiner (term a) result))))
  (iter a null-value))

; Recursive Accumulate:
(define (accumulate combiner null-value term a next b)
  (if (> a b)
      null-value
      (combiner (term a) (accumulator null-value term (next a) next b))))

; Sum & Product using Accumulate:

(define (sum term a next b)
  (accumulate + 0 term a next b))

(define (product term a next b)
  (accumulate * 1 term a next b))


; Full work to figure-out below:
;---------------------------------------
(define (product-recr term a next b)
  (if (> a b)
      1                 ; * by 1, instead of + 0 for <sum>
      (* (term a)
         (product-recr term (next a) next b))))

 (define (sum term a next b)
   (if (> a b)
       0
       (+ (term a)
          (sum term (next a) next b))))

;Iter Sum:
(define (sum term a next b)
  (define (iter a result)
    (if (> a b)
        result
        (iter (next a) (+ (term a) result))))
  (iter a 0))
;---------------------------------------
; Recr:
(define (accumulate combiner null-value term a next b)
  (define (combiner null-value current-term)
    (+ null-value current-term))
  (if (> a b) null-value
              ( accumulate combiner (combiner null-value current-term) term a next b)))

;  Iteracc:
(define (accumulate combiner null-value term a next b)
  (define (combiner result current-term)
    (if (> current-term result)
        result
        (combiner (+ result current-term) (next a))))
  (combiner 0 a))
;---------------------------------------
;
;
; Looking at where sum and product are different:

(define (product-recr term a next b)
  (if (> a b)
      1
      (* (term a)
         (product-recr term (next a) next b))))

 (define (sum term a next b)
   (if (> a b)
       0
       (+ (term a)
          (sum term (next a) next b))))

; Different at combination operator, and null value:

(define (accumulate combiner null-value term a next b)
  (if (> a b)
      null-value
      (combiner (term a) (accumulator null-value term (next a) next b))))

;   Too soon; taking a hint from online solution--->
;   rather:

(define (sum term a next b)
  (if (> a b)
      <<null-value>>
      (<<combiner>> (term a)
         (<<name>> term (next a) next b))))

;   Now we can incorporate accumulate & combiner:

(define (sum term a next b)
  (if (> a b)
      null-value
      (combiner (term a)
         (accumulate combiner null-value term (next a) next b))))

; Turns out I had it right!

; Redefining <sum> & <product> in terms of <accumulate>:

(define (sum term a next b)
  (accumulate + 0 term a next b))

(define (product term a next b)
  (accumulate * 1 term a next b))

; Holy shit, it's that easy?

; Now defining iterative sum and product, subst what is different:

(define (accumulate-iter combiner null-value term a next b)
  (define (iter a result)
    (if (> a b)
        result
        (iter (next a) (combiner (term a) result))))
  (iter a null-value))

;
-*- mode:scheme;-*-
