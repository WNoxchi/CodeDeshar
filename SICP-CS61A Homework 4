;-------------------------------------------------------------------------------
;   SICP/CS61A  Homework 4  12-Jan-2016 15:27   |   -*- mode:scheme;-*-
;-------------------------------------------------------------------------------
;   Wayne H Noxchi - Nixaloi    12-Jan-2016 15:58
;-------------------------------------------------------------------------------
;   HW Soln: https://github.com/fgalassi/cs61a-sp11/tree/master/homework
;   HW Handout: http://wla.berkeley.edu/~cs61a/reader/nodate-hw.pdf

1.  Write a proc (substitute) that takes 3 args: a list, an old word, a new word
    It should return a copy of the list, but with every occurence of the old
    word replaced by the new word, even in sublists.

(substitute items oldword neword)

;top level: (se [check first list] [substitute butfirst list])

;inner mech: (cond ((empty? items) '())
;                  ((equal? (first list) oldword) neword)
;                  (else oldword))
;How to work on sublists?

(define (map proc items)
    (if (null? items)
        nil
        (cons (proc (car items))
              (map proc (cdr items)) )))
(define (oldnew old new)
    (if (old) new))

(define (substitute items oldword neword)
    (map (oldnew old new) list))

;----------------------------------------
;https://github.com/fgalassi/cs61a-sp11/blob/master/homework/h4.1.scm
(define (substitute items oldword neword)
    (cond ((word? items)
           (if (equal? items oldword) neword items))
          ((list? items) (map (lambda (items) (substitute items oldword neword)) items))))

;-------------------------------------------------------------------------------
;   SICP/CS61A  Homework 4  12-Jan-2016 16:08   |   -*- mode:scheme;-*-
;-------------------------------------------------------------------------------
;   Wayne H Noxchi - Nixaloi
;-------------------------------------------------------------------------------
;   HW Soln: https://github.com/fgalassi/cs61a-sp11/blob/master/homework/h4.2.scm
;   HW Handout: http://wla.berkeley.edu/~cs61a/reader/nodate-hw.pdf

;2.  Now write (substitute2) that takes a list, a list of old words, and a list of
;    new words; the last two lists should be of same length. It should return a
;    copy of the first argument, but with each word that occurs in the 2nd arg
;    replaced by the corresponding word of the 3rd arg.

; idek right now.

;https://github.com/fgalassi/cs61a-sp11/blob/master/homework/h4.2.scm
(define (substitute2 items oldwords newords)
    (cond ((word? items)
           (substitute-words items oldwords newords))
          ((list? items) (map lambda (items) (substitute2 items oldwords newords)) items) ))

(define (substitute-words wd oldwords newords)
    (if (null? oldwords)
        wd
        (if (equal? wd (car oldwords))
            (car newords)
            (substitute-words wd (cdr oldwords) (cdr newords))) ))

; yeah I fucked up like a mofo.
