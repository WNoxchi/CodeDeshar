;-------------------------------------------------------------------------------
;   SICP/CS61A  Homework 1  04-Jan-2016 10:00-12:00 | 05-Jan-2016 10:20 | 06-Jan-2016 15:08
;-------------------------------------------------------------------------------
;   HW Soln: http://reocities.com/Area51/Atlantis/6894/cs61a/week1.txt
;   HW Handout: http://wla.berkeley.edu/~cs61a/reader/nodate-hw.pdf

;2.  Write a proc (squares) that takes a sentence of numbers as its arg & returns
;    a sentence of the squares of the numbers.

(define (squares nums)
    (if (empty? nums)
        '()
        (se (square (first nums))
            (squares (bf nums)) )))

;   If Numbers is empty, return the empty sentence.
;   Otherwise, make a sentence of: (square the first element in Numbers) and
;                                  (run squares on butfirst elements in Numbers)

;-------------------------------------------------------------------------------
;3.  Write a proc (switch) that takes a sent as arg and returns a sent w every
;    word 'I' or 'me' replaced w 'you' & every 'you' replaced w 'me' except 1st
;    which is 'I'

;   (HWsoln): The tricky part is that the first word of the sentence must be
;treated specially, so there has to be a top-level procedure that handles
;it and also invokes a recursive subprocedure for the rest of the words:

(define (switch sent)
    (se (switchFirst (first sent))
        (switchRest (bf sent)) ))

(define (switchFirst wd)
    (cond ((equals? wd 'you) 'I)
          ((equals? wd 'I) 'you)
          ((equals? wd 'me) 'you)
          (else wd) ))

(define (switchRest sent)
    (if (empty? sent)
        '()
        (se (switchCxa (first sent))
            (switchRest (bf sent)) )))

(define (switchCxa wd)
    (cond ((equal? wd 'you) 'me)
          ((equal? wd 'I) 'you)
          ((equal? wd 'me) 'you)
          (else wd) ))

;-------------------------------------------------------------------------------
;4.  Write a predicate <ordered?> that takes a sentence of numbers as arg and
;    returns #t if #'s in ascending order, #f otherwise.

(define (ordered? sent)
    (cond ((empty? (bf sent)) #t)
          ((> (first sent) (first (bf sent))) #f)
          (else (ordered? (bf sent))) ))

;-------------------------------------------------------------------------------
;5.  Write a proc (endsE) that takes a sentence as its arg and returns a sentence
;    containing only words of arg ending in E/e.

(define (ends-e sent)
    (cond ((empty? sent) '())
          ((equal? (last (first sent)) 'e)
           (se (first sent) (ends-e (bf sent))))
          (else (ends-e (bf sent)))))

;-------------------------------------------------------------------------------
;6.  Devise a way to test of <or> is a special form in a Scheme interpreter.

(or 1 2 x)

;   If <or> is ordinary, all elements will be evaluated, and an error will occur xä there's no definition of x.
;   If <or> is special, the interpreter will stop and return <1> when it gets to it.
;   However it's possible the interpreter may just evaluate left to right or whatever. You could also do:

(define (infiniteLoop) (infiniteLoop))
(or 1 (infiniteLoop))

;   (infiniteLoop) just calls itself recursively infinitely. So if <or> is ordinary, all elements are evaluated before applying it, and you get an infinite loop. If it's special, 1 is eval'd and returned.

;-------------------------------------------------------------------------------

;1.  [1.06]  What's going on is this: defining <new-if> doesn't matter for evaluating (new-if (= 2 3) 0 5) because the answer is the same for ordinary and special forms. All parts are evaluated before applying the proc.

(sqrt-iter (improve guess x) x)

;The issue with <sqrt-iter> is that in <new-if> there is no way to signal when to stop. First evaluate sqrt-iter. Its value is an ordinary proc, so the rest of the args are evaluated normally. Second evaluate the two args to sqrt-iter. For: (sqrt-iter 1 4) they come out to 1 and 4. Now apply sqrt-iter to 1 and 4. <1> subst for <guess> and <4> for <x>. You get:

(new-if (good-enough? 1 4)
    1
    (sqrt-iter (improve 1 4)
               4))

;   Now evaluate this. Here's the problem: <new-if> is ordinary so we evaluate all parts normally. This creates an infinite recursive call chain to sqrt-iter because each call is waiting for it's sub-calls to evaluate before itself evaluating. This never ends. For <if> a special proc, Scheme tests <good-enough?> BEFORE evaluating the inner sqrt-iter expression. It invokes <sqrt-iter> everytime the <good-enough?> call returns true, but since it's doing this iteratively, it eventually gets to true and returns a value. <new-if> waits for the full (infinite) recursive chain of calls before testing <good-enough?>.

;1.  [1.06]  New-if isn't defined properly. <if> is different from normal procs
;    in that it doesn't evaluate all it's args by default. (proc arg1 arg2);
;    (new-if predicate consequent alternate) --> <new-if> will evaluate on all
;    args, i.e. on the consequent and the alternate, every time.

;   -*- mode:scheme;-*-
