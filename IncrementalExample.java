package thread;

import java.util.concurrent.locks.ReentrantLock;

public class IncrementalExample implements Runnable {

	public static int value = 0;
	public static final ReentrantLock lock = new ReentrantLock();

	@Override
	public void run() {
		// TODO Auto-generated method stub
		for(int i=0;i<10000;i++){
//			IncrementalExample.value++;

			IncrementalExample.lock.lock();
			try{
				IncrementalExample.value++;
			}finally{
				IncrementalExample.lock.unlock();
			}
		}
	}


	public static void main(String[] args){
		Thread t = new Thread(new IncrementalExample());
		t.start();

		for(int i=0;i<10000;i++){
//			IncrementalExample.value++;
			

			IncrementalExample.lock.lock();
			try{
				IncrementalExample.value++;
			}finally{
				IncrementalExample.lock.unlock();
			}
		}

		
		try {
			Thread.sleep(100);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println(IncrementalExample.value);

	}


}


//IncrementalExample.lock.lock();
//try{
//	IncrementalExample.value++;
//}finally{
//	IncrementalExample.lock.unlock();
//}