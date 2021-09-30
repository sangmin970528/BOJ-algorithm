import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        String str = br.readLine();
        StringTokenizer st = new StringTokenizer(str, " ");
        long N = Integer.parseInt(st.nextToken());
        long M = Integer.parseInt(st.nextToken());
        ArrayList<Long> list = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            long x = Integer.parseInt(br.readLine());
            list.add(x);
        }
        list.sort(Comparator.naturalOrder());
        long max = list.get(list.size() - 1);
        long start = 1L;
        long end = max * M;
        long answer = end;
        while (start <= end) {
            long mid = (start + end) / 2;
            long sum = 0L;
            for (Long n : list) {
                sum += mid / n;
            }
            if (sum >= M) {
                end = mid - 1;
                answer = mid;
            } else {
                start = mid + 1;
            }
        }
        System.out.println(answer);
    }
}
