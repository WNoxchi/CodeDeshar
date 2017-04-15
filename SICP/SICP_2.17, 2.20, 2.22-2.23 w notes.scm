;-------------------------------------------------------------------------------
; SICP_2.23 / CS61A
;-------------------------------------------------------------------------------
; Give an implementation of (forEach). Input: proc and list. Output: applies
;   proc to each element in turn. (forEach)'s output values are not used - it is
;   used with procs that perform actions like printing.
;-------------------------------------------------------------------------------
; Start:  30-Dec-2015 13:13 | Finish: 30-Dec-2015 13:44

;---------------------------------------
(define (forEach proc items)
  (cond ((null? items) #t)
        (else (proc (car items))
              (forEach proc (cdr items)))))
;---------------------------------------

(define x (list 57 321 88))
(display x)

;>> (57 321 88)

; Aha! We want output to be values that can be used alone, not a whole list.
; So the way it should work w printing:

(forEach (lambda (x)
            (newline)
            (display x))
         (list 57 321 88))
;>> 57
;>> 321
;>> 88

(define (forEach proc items)
  (if (null? items)
      nill
      ((proc (car items)) (forEach proc (cdr items)))
      ))

; Above doesn't work bc proc (forEach) has to return 1 value at a time...
; So we can create a retainer list... or just have that as output and rewrite?


(define (forEach proc items)
  (if (null? (cdr items))
      (proc items)
      (forEach proc (car items))))

; doesnt work..

(define (forEach proc items)
  (define retainer (list ))
  (if (null? (cdr items))
      (append retainer (proc items))
      (append retainer (proc (car items)))))

; only returns first element..

;---------------------------------------
(define (forEach proc items)
  (cond ((null? items) #t)
        (else (proc (car items))
              (forEach proc (cdr items)))))

; Ahaaa. I didn't know you could add multiple statements to an else like that.
;   Also that's what the book meant by an arbitrary return value such as #true.

; If the list is empty, return true. Otherwise: perform the procedure on the
;   first element, and perfor (forEach) with the same proc on the cdr list.

; final help: http://www.billthelizard.com/2011/01/sicp-221-223-mapping-over-lists.html


;-------------------------------------------------------------------------------
; SICP_2.22 / CS61A
;-------------------------------------------------------------------------------
; Lious Reasoner tries to rewrite a (squareList) procedure so that it evolves an
;   iterative process, but is having trouble getting it to work.
;-------------------------------------------------------------------------------
; Start:  30-Dec-2015 12:18 | Finish: 30-Dec-2015 12:58


(define (squareList items)
  (define (iter things answer)
    (if (null? things)
        answer
        (iter (cdr things)
              (cons (square (car things))
                    answer))))
  (iter items nil))

; This produces a list in reverse order. Why?
; -->>  It constructs backwards through it; you need to go down instead of up.
;     If you're doing it iteratively it ends up backwards like this. The recr
;     algo delays construction until the end; iter does it each step.

; He then interchanging the argument to cons:

(define (squareList items)
  (define (iter things answer)
    (if (null? things)
        answer
        (iter (cdr things)
              (cons answer
                    (square (car things))))))
  (iter items nil))

; This also doesn't work. Explain.
; -->>  It seems like the proc is constructing empty lists on each step with
;     the element to be squared. It becomes a nested mess. It's combining an
;     empty list with an integer.
;       To fix this, use append on answer instead of cons, so that we're adding
;     the element of that list to the final answer and not combining empty
;     lists, and use list on the next thing so it we make a list of it to
;     append our answers to, instead of separate lists of single integers:

(define (squareList items)
  (define (iter things answer)
    (if (null? things)
        answer
        (iter (cdr things)
              (append answer
                    (list (square (car things)))))))
  (iter items nil))

;-------------------
; use: (define nil (list )) for BiwaScheme interpreter v 0.5.7
; Checked answer against: http://www.billthelizard.com/2011/01/sicp-221-223-mapping-over-lists.html

;-------------------------------------------------------------------------------
; SICP_2.20 / CS61A
;-------------------------------------------------------------------------------
; Use dotted-tail notation to write (sameParity) that takes one or more ints and
;   returns a list of all args that have same even|odd parity as 1st arg.
;-------------------------------------------------------------------------------
; Start:  29-Dec-2015 16:28 | Finish: 29-Dec-2015 16:46

(define (sameParity . input)
  (parityChecker (car input) (cdr input))

(define (parityChecker element1 cdrList)
  (if (= (car cdrList) (element1))
      (append element1 (car cdrList))
      (parityChecker element1 (cdr cdrList))))

; Aldashna:
(sameParity 1 2 3 4 5 6 7)
(1 3 5 7)
(sameParity 2 3 4 5 6 7)
(2 4 6)

;-------------------------------------------------------------------------------
; SICP_2.17 / CS61A
;-------------------------------------------------------------------------------
; Define a proc (lastPair) that returns the list that contains only the last
;   element of a given non-empty list.
;-------------------------------------------------------------------------------
; Start:  28-Dec-2015 14:56 | Finish: 28-Dec-2015 15:04

(define (lastPair list)
  (if (= 1 (length list))
      list
      (lastPair (cdr list))))

; Aldashna:
(lastPair (list 23 72 149 34))
>>  (34)

;-------------------------------------------------------------------------------
; NOTES: ch 2.21: Representing Sequences: List Operations:

(define (listref items n)
    (if (= n 0)
        (car items)
        (listref (cdr items) (- n 1))))

;  recr list length:

(define (length items)
    (if (null? items)
        0
        (+ 1 (length (cdr items)))))

; iterative list length:

(define (length items)
    (define (lengthiter a count)
        (if (null? a)
            count
            (lengthiter (cdr a) (+ 1 count))))
    (lengthiter items 0))

(define squares (list 1 4 9 16 25))
(define odds (list 1 3 5 7 9))

; appending 2 lists recursively:

(define (append list1 list2)
    (if (null? list1)
        list2
        (cons (car list1) (append (cdr list1) list 2))))
;

(define (length items)
    (if (null? items)
        0
        (+ 1 (length (cdr items)))))

(define (lastPair list)
  (if (= 1 (length list))
      list
      (lastPair (cdr list))))

(define squares (list 1 4 9 16 25))
;-------------------------------------------------------------------------------
; -*- mode:scheme;-*-
