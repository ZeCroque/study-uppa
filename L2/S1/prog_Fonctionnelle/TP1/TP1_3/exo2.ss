(define (change somme devise) (begin
                                 (define taux 0)
                                 (cond
                                   ((= devise 'USD)(+  taux 1.064))
                                   ((= devise 'GPB)(+  taux 0.852))
                                   ((= devise 'JPY)(+  taux 120.494))
                                   ((= devise 'RUB)(+  taux 61.974))
                                   ((= devise 'CNY)(+  taux 7.319))
                                   ((= devise 'INR)(+  taux 71.098)))
                                 (* taux somme)
                                 ))

(change 20 'USD)