; SICP 1.30   | 17 Ogoi 2015 || 17-Dec-2015 23:14
; rewrite the sum proc st it sums iteratively:
; reference: http://www.billthelizard.com/2010/04/sicp-exercise-130-iterative-sums.html
;------------------------
(define (sum term a next b)
  (define (iter a result)
    (if <<??>>
        <<??>>
        (iter <<??>> <<??>>)))
  (iter <<??>> <<??>>))
;------------------------

(define (sum term a next b)
  (define (iter a result)
    (if (> a b)
        result
        (iter (next a) (+ (term a) result))))
  (iter a 0))

; if a > b =? return result.
; otherwise: iterate: (next term in series) (add term a to result)
; begin iteration at a, result total at 0

; I really need to build intuition.. this is too obvious yet taking me too long..
;-*-mode:scheme;-*-
