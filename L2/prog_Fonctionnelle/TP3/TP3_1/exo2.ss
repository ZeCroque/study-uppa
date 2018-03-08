(define course '(Tomate Orange Fraise Poire Pomme Framboise Coton))
(define course2 '(Poivron Tomate Artichaut Poire Framboise Poulet))

(define (produit-Julie? l elt)
  (cond
    ((null? l) #f)
    ((equal? (car l) elt) #t)
    (else (produit-Julie? (cdr l) elt))
  )
)

(define (produit-Double l1 l2)
  (if(null? l2)
     '()
      (if (produit-Julie? l1 (car l2))
         (cons (car l2) (produit-Double l1 (cdr l2)))
         (produit-Double l1 (cdr l2))
      )
   )
)

(define (produit l1 l2)
  (if(null? l2)
     l1
     (if (produit-Julie? l1 (car l2))
       (produit l1 (cdr l2))
       (cons (car l2) (produit l1 (cdr l2))))

         
   )
)



(produit-Julie? course 'fraise)

(produit-Double course course2)

(produit course course2)