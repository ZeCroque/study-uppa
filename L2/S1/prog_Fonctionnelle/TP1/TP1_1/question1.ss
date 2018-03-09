(define (carre a) (* a a))
(define (cube a) (* a a a))

(define (f x y) ( + ( / ( - x 3) (+ (carre y) 1)) ( / 1 ( + (cube x) 3))))

(f 3 1)
