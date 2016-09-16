import java.util.*;
class AddNum
{
	public static void BubbleSort(int a[])
	{
		int l=a.length;
		for(int i=l-1;i>=0;i--)
		{
			for(int j=0;j<i;j++)
			{
				if(a[j]>a[j+1])
				{
					int temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
	}
	public static void display(int a[])
	{
		for(int i=0;i<6;i++)
		{
			System.out.print(a[i]+" ");
		}
	}
	public static void main(String args[])
	{
		Scanner s=new Scanner(System.in);
		int arr[]=new int[6];
		System.out.println("enter the values in the array ");
		for(int i=0;i<6;i++)
		{
			arr[i]=s.nextInt();
		}
		BubbleSort(arr);
		display(arr);
		s.close();	
		
	}
	
	
}
