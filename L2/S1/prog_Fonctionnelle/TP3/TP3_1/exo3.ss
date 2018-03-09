(define (comptebon e l)
  (if (null? l)
      0
      (cond 
        ((> e 0) (cons((car l)(comptebon (- e (car l)) (cdr l)))))
        ((= e 0) (car l))
        (else #f)
      )
  )
)

(comptebon 21 '(1 1 3 5 7 10 12 15))