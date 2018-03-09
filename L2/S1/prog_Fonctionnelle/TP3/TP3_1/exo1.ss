(define(somme l)
  (if(null? (cdr l))
            (car l)
            (+ (car l) (somme (cdr l)))
  )
)

(define(moyenne l)
  (/(somme l)(length l)))

(define(notes l moyenne)
  (cond
    ((null? l)0)
    ((> (car l) moyenne)(+ 1 (notes (cdr l) moyenne)))
    (else(+ 0 (notes (cdr l) moyenne)))
   )
 )

(define(taux-reussite l)
  (/(*(notes l (moyenne l) )100)(length l))
 )

(define list '(10 20))
(moyenne list)
(display(taux-reussite list))(display"%")