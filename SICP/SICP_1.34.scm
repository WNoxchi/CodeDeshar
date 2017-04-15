;SICP 1.34    Start: 18-Dec-2015 15:33    Finish:  18-Dec-2015 15:39
;-------------------------------------------------
(define (square x) (* x x))

(define (f g) (g 2))

;(f square)
;=> 4
;(f (lambda (z) (* z (+ z 1))))
;=> 6

; What happens if we ask the interpreter to eval: (f f) ? Explain.
;-------------------------------------------------

; Wouldn't it do nothing because <<lambda>> is a proc defined 'on the fly'?
; Aha!
; (f g) calls (g 2)
; -> so (f f) calls (f 2) which calls (2 2). It's a recursive call.
; 2 isn't a proc, so error is reported.
