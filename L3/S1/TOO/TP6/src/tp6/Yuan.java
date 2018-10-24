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
public class Yuan extends Devise 
{
    private static final double TAUX_YUAN_DOLLAR=6.59169;  
    private static final double TAUX_YUAN_EURO=7.79636;
    
    
    public Yuan()
    {
        this.nom="Yuan";
        this.symbole="¥";       
    }

    @Override
    public double conversion(double montant, Devise devise) 
    {
        if (devise.getNom().equals("Euro"))
        {
            return montant+montant*Yuan.TAUX_YUAN_EURO;
        }
        return montant+montant*Yuan.TAUX_YUAN_DOLLAR;
    }

    @Override
    public String getNom() 
    {
        return this.nom;
    }
}
