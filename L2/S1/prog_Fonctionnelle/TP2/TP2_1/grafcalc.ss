; grafcalc.ss
; Programmation fonctionnelle TP2 , programmation d'une calculette
; (c) Eric Gouardères, Mars 2015



(#%require scheme)
(#%require scheme/gui/base)

; expression saisie (sous forme de liste)
(define operateur '())
(define operande1 0)
(define operande2 0)

(define saisie_op1 (lambda (n)
                     (begin
                       (set! operande1 (add (mul operande1 10) n))
                       (number->string n))))


(define saisie_op2 (lambda (n)
                     (begin
                       (set! operande2 (add (mul operande2 10) n))
                       (number->string n))))

(define saisie_op (lambda (op)
                    (begin
                      (set! operateur op)
                      (symbol->string op))))

; opération en cours  
(define etat_calculette saisie_op1)

; Gestion de l'afficheur

(define flag_zero #f) ; indique que l'opérande n'est pas encore saisi et qu ele zero affiché n'est pas significatif

(define clear (lambda ()
                  (send afficheur set-value "0")))

(define affiche (lambda (exp)
                  (let ((texte (send afficheur get-value)))
                  (if flag_zero
                      (send afficheur set-value (string-append (substring texte 0 (sou (string-length texte) 1)) exp))
                      (send afficheur set-value (string-append texte exp))))))


; creation de l'interface de la calculette
; Make a frame by instantiating the frame% class
(define frame (make-object frame% "Calculette"))
(define afficheur(make-object text-field% "" frame void ""))

(define panel (make-object horizontal-panel% frame))
(make-object button% "7" panel 
  (lambda (button event) 
    (begin
    (affiche (etat_calculette 7))
    (set! flag_zero #f))))

(make-object button% "8" panel 
  (lambda (button event) 
    (begin
    (affiche (etat_calculette 8))
    (set! flag_zero #f))))


(make-object button% "9" panel 
  (lambda (button event) 
    (begin
    (affiche (etat_calculette 9))
    (set! flag_zero #f))))


(make-object button% "add" panel 
  (lambda (button event) 
    (begin 
      (set! flag_zero #f)
      (set! etat_calculette saisie_op)
      (affiche " ")
      (affiche (etat_calculette 'add))
      (affiche " ")
      (set! etat_calculette saisie_op2)
      (affiche (etat_calculette 0))
      (set! flag_zero #t))))

(define panel1 (make-object horizontal-panel% frame))

(make-object button% "4" panel1 
  (lambda (button event) 
    (begin
    (affiche (etat_calculette 4))
    (set! flag_zero #f))))


(make-object button% "5" panel1 
  (lambda (button event) 
    (begin
    (affiche (etat_calculette 5))
    (set! flag_zero #f))))


(make-object button% "6" panel1 
  (lambda (button event) 
    (begin
    (affiche (etat_calculette 6))
    (set! flag_zero #f))))


(make-object button% "sou" panel1 
  (lambda (button event) 
    (begin 
      (set! flag_zero #f)
      (set! etat_calculette saisie_op)
      (affiche " ")
      (affiche (etat_calculette 'sou))
      (affiche " ")
      (set! etat_calculette saisie_op2)
      (affiche (etat_calculette 0))
      (set! flag_zero #t))))

(define panel2 (make-object horizontal-panel% frame))
(make-object button% "1" panel2 
  (lambda (button event) 
      (begin
    (affiche (etat_calculette 1))
    (set! flag_zero #f))))


(make-object button% "2" panel2 
  (lambda (button event) 
      (begin
    (affiche (etat_calculette 2))
    (set! flag_zero #f))))


(make-object button% "3" panel2 
  (lambda (button event) 
    (begin
    (affiche (etat_calculette 3))
    (set! flag_zero #f))))


(make-object button% "mul" panel2 
  (lambda (button event) 
    (begin 
      (set! flag_zero #f)
      (set! etat_calculette saisie_op)
      (affiche " ")
      (affiche (etat_calculette 'mul))
      (affiche " ")
      (set! etat_calculette saisie_op2)
      (affiche (etat_calculette 0))
      (set! flag_zero #t))))

(define panel3 (make-object horizontal-panel% frame))

(make-object button% "0" panel3 
  (lambda (button event) 
    (begin
    (affiche (etat_calculette 0))
    (set! flag_zero #f))))


(make-object button% "=" panel3 
  (lambda (button event) 
    (begin
      (set! flag_zero #f) 
    (if (equal? etat_calculette saisie_op2)
        (begin
          (affiche " = ")
          (set! operande1 (eval (list operateur operande1 operande2)))
          (set! operande2 0)
          (set! operateur '())
          (affiche (number->string operande1))
          (set! etat_calculette saisie_op1))
        (affiche "Erreur")))))

(make-object button% "C" panel3 
  (lambda (button event) 
    (begin (set! etat_calculette saisie_op1)
           (set! operateur '())
           (set! operande1 0)
           (set! operande2 0)   
           (clear)
           (set! flag_zero #t))))

(make-object button% "div" panel3 
  (lambda (button event) 
    (begin 
      (set! flag_zero #f)
      (set! etat_calculette saisie_op)
      (affiche " ")
      (affiche (etat_calculette 'div))
      (affiche " ")
      (set! etat_calculette saisie_op2)
      (affiche (etat_calculette 0))
      (set! flag_zero #t))))

; affichage de la calculette (Show the frame by calling its show method)
; initialisation de l'afficheur
(define (gcalculet)
(send frame show #t)
(affiche "0")
(set! flag_zero #t)
  )

(gcalculet)