;-------------------------------------------------------------------------------
;   SICP/CS61A  Homework 3  11-Jan-2016 15:17   |   -*- mode:scheme;-*-
;-------------------------------------------------------------------------------
;   Wayne H Noxchi - Nixaloi
;-------------------------------------------------------------------------------
;   HW Soln:
;   HW Handout: http://wla.berkeley.edu/~cs61a/reader/nodate-hw.pdf

;2.  Write a proc, (next-perf n) that tests numbers starting with n and continuing
;    with n+1, n+2,... until the next perfect number is found. You can eval
;    (next-perf 29) to solve the problem. You'll need a (sum-of-factors) subproc.

(define (next-perf n)
    (if (= n (sum-of-factors n))
        n
        (next-perf (+ n 1))))

(define (sum-of-factors n)
    (lambda (x) (1))
    (let (factor (if (= 0 (n mod x)) x 0))
        (if (> x (/ n 2))
            factor
            (+ x 1) )))

;I'm not confident about this lambda and let going on..

;----------------------------------------
;I don't really know wtf is going on in this answer: 
;https://github.com/fgalassi/cs61a-sp11/blob/master/homework/h3.2.scm
;
;(define (upto start end)
;  (if (> start end)
;    '()
;    (sentence start (upto (+ start 1) end))))
;
;(define (is_divisor_of? n)
;  (lambda (m) (= (remainder n m) 0)))
;
;(define (factors n)
;  (filter (upto 1 (- n 1)) (is_divisor_of? n)))
;
;(define (sum sent)
;  (if (empty? sent)
;    0
;    (+ (first sent) (sum (butfirst sent)))))
;
;(define (sum-of-factors n)
;  (sum (factors n)))
;
;(define (perfect? n)
;  (= (sum-of-factors n) n))
;
;(define (next-perf n)
;  (if (perfect? n) n (next-perf (+ n 1))))

;----------------------------------------

;4.  Give an algebraic formula relating the vals of the parameters b, n, counter,
;and product, of the (exp-iter) procs given newar the top of page 45(58) of SICP.
;
;product = b^(n - counter)
;b^n = b^counter * product

;----------------------------------------

;;Experts:
;    Write a procedure (number-of-partitions) that takes an arg n, and returns the
;    number of partitions of that number. A partition is a way the number can be
;    represented: aldashna 5 has 7 partitions (5, 4 1, 3 2, 3 1 1, 2 1 1 1, 1 1 1 1 1, 2 2 1)
;    0 has 1 partition.
;From: https://github.com/fgalassi/cs61a-sp11/blob/master/homework/h3.extra.scm
;
;(define (number-of-partitions n)
;  (define (nop n numbers)
;    (cond ((= n 0) 1)
;          ((or (< n 0) (= numbers 0)) 0)
;          ((> n 0) (+ (nop n (- numbers 1)) (nop (- n numbers) numbers)))))
;  (nop n n))
;
;; Counting partitions is like making change, where coins are "the nonnegative
;; numbers equal or less than n"
;;
