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
public class Dollar extends Devise
{
    private static final double TAUX_DOLLAR_YUAN=0.151725;  
    private static final double TAUX_DOLLAR_EURO=0.845534;
    
    
    public Dollar()
    {
        this.nom="Dollar";
        this.symbole="$";       
    }

    @Override
    public double conversion(double montant, Devise devise) 
    {
        if (devise.getNom().equals("Euro"))
        {
            return montant+montant*Dollar.TAUX_DOLLAR_EURO;
        }
        return montant+montant*Dollar.TAUX_DOLLAR_YUAN;
    }

    @Override
    public String getNom() 
    {
        return this.nom;
    }
}
