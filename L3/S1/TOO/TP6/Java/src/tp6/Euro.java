/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp6;

/**
 *
 * @author gcroquefer
 */
public class Euro extends Devise
{
    private static final double TAUX_EURO_YUAN=0.128320;
    private static final double TAUX_EURO_DOLLAR=1.18268;
    
    
    public Euro()
    {
        this.nom="Euro";
        this.symbole="€";       
    }

    @Override
    public double conversion(double montant, Devise devise) 
    {
        System.out.println(devise.getNom());
        if (devise.getNom().equals("Dollar"))
        {
            return montant+montant*Euro.TAUX_EURO_DOLLAR;
        }
        return montant+montant*Euro.TAUX_EURO_YUAN;
    }

    @Override
    public String getNom() 
    {
        return this.nom;
    }
    
    
    
}
