package tp4;

import java.util.Random;

public class TirageLoto 
{
	public static final int _nombre=48;
	private int[] _resultatTirage;
	
	public TirageLoto()
	{
		_resultatTirage=new int[_nombre];
	}
	
	public void tirage()
	{
		for(int i=0; i<_nombre; i++)
		{
			_resultatTirage[i]=tirageInterne(i);
		}
	}
	
	private int tirageInterne(int i)
	{
		int randomNumber = 0;
		Random rand = new Random(); 
		randomNumber = rand.nextInt(_nombre + 1);
		boolean yetDrawn=false;
		
		for(int j=0; j<i; j++)
		{
			if(this._resultatTirage[j]==randomNumber)
			{
				yetDrawn=true;
				break;
			}
		}
		if(yetDrawn)
		{
			return tirageInterne(i);
		}
		return randomNumber;
		
	}
	
	@Override
	public String toString()
	{
		String tirage=new String();
		for(int value : this._resultatTirage)
		{
			tirage+=value+"\n";
		}
		return tirage;		
	}
}
