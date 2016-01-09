;-------------------------------------------------------------------------------
;   SICP / CS61A    |   Project 1: Ткъацхьа/Tq̇acẋa - 8    |   majority.scm
;-------------------------------------------------------------------------------
;   Start:  09-Jan-2016 14:35   |   Fin:  09-Jan-2016 15:41
;-------------------------------------------------------------------------------
;   http://wla.berkeley.edu/~cs61a/reader/nodate-21.pdf
;>>>Define a func (majority) that takes 3 strats as args and produces a strat as
;   a result, s.t. the result strat always decides whether or not to HIT by
;   conslting the 3 arg strats and going with the amjority. i.e. result strat
;   should only return #t IFF ≥2 of the 3 arg strats return #t.


; idk why I should load "higher-order" but I see it done so I will.
(load "higher-order")

(define (majority strat1 strat2 strat3)
; So I need to see what other strats take as args and use that as a Lambda
; Strats act on: <hand> <dealer-card>
    (lambda (hand dealer-card)
        (cond ((and (strat1 hand dealer-card) (strat2 hand dealer-card)))
              ((and (strat1 hand dealer-card) (strat3 hand dealer-card)))
              ((and (strat2 hand dealer-card) (strat3 hand dealer-card))) )))
; Now idk how I should account for suit-strategy wanting a suit.. how to account
;   for strategies that rely on different arguments/conditions.
; I think I understand lambda better now.
; Check if any conditions true (all 3 logical combinations of the 2 out of 3 condition)
;   using <hand> and <dealer-card> as args to the strats.

;----------------------------------------
; Checking against: https://github.com/fgalassi/cs61a-sp11/blob/master/projects/blackjack/normal/majority-strategy.scm

(load "higher-order")

; NB: bool-num and 1 are used because apparently you can't have a sentence of
; booleans so i am tricking it into a sequence of binary digits

(define (majority-strategy first-strategy second-strategy third-strategy)
  (lambda (hand dealer-card)
    (majority-of? 1 (sentence                                           ; OK, I see what he's doing with (majority-of?) and (bool-num)
                      (bool-num (first-strategy hand dealer-card))
                      (bool-num (second-strategy hand dealer-card))
                      (bool-num (third-strategy hand dealer-card))))))

(define (bool-num bool)
  (if bool 1 0))

(define (count-equal-to elem sent)                              ; Ohhhhh, I was confused about this.
  (reduce 0                                                     ; he defined (majority-of?) himself
          (lambda (total current-elem)
            (if (equal? elem current-elem)
              (+ 1 total)
              total))
          sent))

(define (majority-of? elem sent)
  (> (count-equal-to elem sent) (/ (count sent) 2)))    ; I don't know what (reduce) is
;----------------------------------------
;   Ok so (reduce) takes a 2-parameter function and applies it to the head of the list,
;   and the reduction of the rest of the list.

; So if I understand the (count-equal-to) proc:
;   apply reduce of function (Lambda) to 0 through sent
;   Lambda definition: args: <total> & <current-elem>     <<-- as you can see, 2 parameter function
;       if element = current-element ==> total + 1
;       otherwise just the total itself.
;>> That's how he counts up the number of 1's (#t's), divides that by the amount of the sentence (the total)
;       to determine if he has a majority or not.


;   I am not sure if my proc would work or not bc I don't have a good-enough interpreter/environment for it all,
;   but since he's using official solutions (which as of this time are no longer online) I'll work on getting
;   what I can do, up to that standard.

;   To write this on my own I'll have to:
        ;1.  write the (majority-strategy) proc, using a Lambda to input <hand> & <dealer-card>
        ;    args into the 3 different strategy procs.
        ;2.  use/write a (majority-of) proc for use as a predicate, checking if a sentence of
        ;    boolean values returned by the 3 strats has a majority of 1.
        ;    -->> define (majority-of) taking <element> and <sentnce> as args, and returning whether true
        ;        if number of elements in the sentnce equalling 1 (returning true) is greater than half
        ;        the number of elements in the sentnce.
        ;3.  write a (bool-num <bool>) proc that checks if <bool> = #t ==>> 1, = #f ==> 0
        ;4.  finally write a (count-equal-to <element> <sentnce>) which starts at 0 and adds
        ;    1 to it for every item in the sentnce equal to <element>.
        ;        -->> this proc uses a (reduce) proc to do this, with: start: 0, list: sent, function:
        ;             (lambda (<total> <current-element>))

 ; oy good luck future me!
