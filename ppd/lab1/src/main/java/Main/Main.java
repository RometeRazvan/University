package Main;
import java.util.Arrays;
import java.util.Random;

public class Main {

    public static class T1 extends Thread {
        private int start, end;
        private int[] a, b, c;

        public T1(int start, int end, int[] a, int[] b, int[] c) {
            this.start = start;
            this.end = end;
            this.a = a;
            this.b = b;
            this.c = c;
        }

        public void run() {
            System.out.println(currentThread().getName() + " " + start + " " + end);
            for(int i = start; i < end; ++i) {
                c[i] = (int) Math.sqrt((a[i] + b[i]) * (a[i] + b[i]) * (a[i] + b[i]) * (a[i] + b[i]) * (a[i] + b[i]));
            }
        }
    }
    public static void main(String[] args) throws InterruptedException {
        int m = 10000000;
        int n = 5;

        int a[] = new int[m];
        int b[] = new int[m];
        int c[] = new int[m];
        int d[] = new int[m];

        Random random = new Random();

        for(int i = 0; i < m; ++i) {
            a[i] = random.nextInt(n);
            b[i] = random.nextInt(n);
        }

        System.out.println(Arrays.toString(a));
        System.out.println(Arrays.toString(b));

        int p = 3;
        int chunk_size = m / p;
        int reminder = m % p;
        int start = 0, end;

        T1[] threads = new T1[p];

        long start_t = System.currentTimeMillis();

        for(int i = 0; i < p; ++i) {
            end = start + chunk_size;

            if(reminder > 0) {
                ++ end;
                -- reminder;
            }

            threads[i] = new T1(start, end, a, b, c);
            threads[i].start();

            System.out.println(start + " " + end);

            start = end;
        }

        for(int i = 0 ; i < p; ++i) {
            threads[i].join();
        }

        System.out.println(System.currentTimeMillis() - start_t);

        for(int i = 0; i < m; ++i)
            d[i] = (int) Math.sqrt((a[i] + b[i]) * (a[i] + b[i]) * (a[i] + b[i]) * (a[i] + b[i]) * (a[i] + b[i]));

        System.out.println(System.currentTimeMillis() - start_t);
    }
}
