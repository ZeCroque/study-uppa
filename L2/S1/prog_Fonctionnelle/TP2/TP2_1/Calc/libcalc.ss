; libcalc.ss
; Programmation fonctionnelle TP2 , programmation d'une calculette
; (c) Eric Gouardères, Mars 2015


; définition des opérateurs de la calculette

(define incrementer 
  (lambda (n) (+ n 1)))

(define decrementer 
  (lambda (n) (- n 1)))

(define non_zero? 
  (lambda (n) (not (zero? n))))

(define sup_egal? 
  (lambda (n1 n2) (>= n1 n2)))

(define (evalue op op1 op2)
  (op op1 op2))

; définition  de l'interface
(define (calculet)
  (begin
    (display "-------------------------------")
    (newline)
    (display "operateur ? (fin pour arreter) ")
    (let ((op (read)))
      (cond ((or (equal? op 'add)
                 (equal? op 'sou)
                 (equal? op 'mul)
                 (equal? op 'div))            
             (display "operande1 : ")
             (let ((op1 (read)))
               (display "operande2 : ")
               (let ((op2 (read)))
                 (newline)
                 (display "Evaluation de ")
                 (display op)
                 (display " ")
                 (display op1)
                 (display " ")
                 (display op2)
                 (display ", résultat : ")
                 (display ((eval op (interaction-environment) ) op1 op2))
                 (newline)
                 (calculet))))
            ((equal? op 'fin) (display "arret calculette"))
            (else (display "erreur d'opérateur") (newline) (calculet))))))

