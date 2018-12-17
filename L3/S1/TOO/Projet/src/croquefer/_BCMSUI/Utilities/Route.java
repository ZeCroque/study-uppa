package croquefer._BCMSUI.Utilities;

import java.util.Arrays;
import java.util.Random;

import javafx.util.Pair;

public class Route 
{
	
	//STATIC
	private static Pair<Integer,Integer> startPoint;
	private static Pair<Integer,Integer> endPoint;
	
	private static Pair<Integer, Integer> genCoord()
	{
		Random rand = new Random();
		return new Pair<>(rand.nextInt(10),rand.nextInt(10));
	}
	
	private static void genCoords()
	{
		do
		{
			Route.startPoint=Route.genCoord();
			Route.endPoint=Route.genCoord();
		} while(Route.startPoint.equals(Route.endPoint));
	}
	
	//INSTANCE
	private boolean[][] roadMatrix;
	
	public Route()
	{
		if(Route.startPoint==null)
		{
			Route.genCoords();
		}
		this.genMatrix();
	}
	
	public Pair<Integer,Integer> getStartPoint()
	{
		return Route.startPoint;
	}
	
	public Pair<Integer,Integer> getEndPoint()
	{
		return Route.endPoint;
	}
	
	public boolean[][] getMatrix()
	{
		return Arrays.copyOf(this.roadMatrix, this.roadMatrix.length);
	}
	

	public int size()
	{
		return 10;
	}
	
	@Override
	public String toString()
	{
		String result=new String();
		for(int i=0; i<10; i++)
		{
			for(int j=0; j<10; j++)
			{
				if(this.roadMatrix[j][i])
				{
					result+="1 ";
				}
				else
				{
					result+="0 ";
				}

			}
			result+="\n";
		}
		return result;
	}

		
	private void genMatrix()
	{
		this.roadMatrix=new boolean[10][10];
		Random rand = new Random();
		int i=Route.startPoint.getKey();
		int j=Route.startPoint.getValue();
		this.roadMatrix[i][j]=true;
		this.roadMatrix[Route.endPoint.getKey()][Route.endPoint.getValue()]=true;
		do
		{
			int coinFlip=rand.nextInt(2);
			int iTarget=i;
			int jTarget=j;
			if((coinFlip==0 && i!=Route.endPoint.getKey()) || (coinFlip==1 && j==Route.endPoint.getValue()))
			{
				if(i<Route.endPoint.getKey())
				{
					iTarget+=rand.nextInt(Route.endPoint.getKey()-i)+1;
					for(int k=i; k<=iTarget; k++)
					{
						this.roadMatrix[k][j]=true;
					}
				}
				else
				{
					iTarget-=rand.nextInt(i-Route.endPoint.getKey())+1;
					for(int k=i; k>=iTarget; k--)
					{
						this.roadMatrix[k][j]=true;
					}
				}

			}
			else if ((coinFlip==1 && j!=Route.endPoint.getValue()) || (coinFlip==0 && i==Route.endPoint.getKey()))
			{
				if(j<Route.endPoint.getValue())
				{
					jTarget+=rand.nextInt(Route.endPoint.getValue()-j)+1;
					for(int k=j; k<=jTarget; k++)
					{
						this.roadMatrix[i][k]=true;
					}
				}
				else
				{
					jTarget-=rand.nextInt(j-Route.endPoint.getValue())+1;
					for(int k=j; k>=jTarget; k--)
					{
						this.roadMatrix[i][k]=true;
					}
				}
				
			}
			i=iTarget;
			j=jTarget;
			

		} while(i!=Route.endPoint.getKey() || j!=Route.endPoint.getValue());
	}
}

