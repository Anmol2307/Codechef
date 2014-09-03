import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Praveen
 */
public class Main {
      public static void main(String[] args) {
            InputStream inputStream = System.in;
            OutputStream outputStream = System.out;
            InputReader in = new InputReader(inputStream);
            PrintWriter out = new PrintWriter(outputStream);
            ANUBGC solver = new ANUBGC();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                  solver.solve(i, in, out);
            out.close();
      }
}

class ANUBGC {
    long memo[][][][] = new long[20][2][2][2];
    int whichDigit;
    List<Integer> list;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        long n = Long.parseLong(in.next());
        if (n < 1 || n > (long) 1e17) throw new RuntimeException("n out of range");
        list = createBinarySequence(n);

        long numerator = 0;
        for (whichDigit = 0; whichDigit <= 9; whichDigit++) {
            for (int i = 0; i < 20; i++)
                for (int j = 0; j < 2; j++)
                    for (int k = 0; k < 2; k++)
                        for (int l = 0; l < 2; l++)
                            memo[i][j][k][l] = -1;

            long ways = dp (0, 1, 0, 0);
            numerator += ways;
        }
        long denomenator =  10 * n;

        long g = gcd (numerator, denomenator);
        numerator /= g;
        denomenator /= g;
        out.println(numerator + "/" + denomenator);
    }

    private List<Integer> createBinarySequence(long n) {
        List<Integer> answer = new ArrayList<>();
        while (n > 0) {
            answer.add((int) (n % 10));
            n /= 10;
        }
        answer.add(0);
        Collections.reverse(answer);
        return answer;
    }

    private long dp(int id, int tight, int hasCome, int actualDigitStarted) {
        long res = memo[id][tight][hasCome][actualDigitStarted];
        if (res != -1)
            return res;

        if (id == list.size()) {
            if (actualDigitStarted > 0 && hasCome > 0)
                res = 1;
            else
                res = 0;
        } else {
            res = 0;
            for (int i = 0; i < 10; i++) {
                if (tight > 0 && i > list.get(id))
                    continue;

                int newId = id + 1;
                int newTight = 0;
                if (tight == 1) {
                    if (i == list.get(id))
                        newTight = 1;
                }
                int newActualDigitStarted = 0;
                if (actualDigitStarted > 0) {
                    newActualDigitStarted = 1;
                } else {
                    if (i != 0)
                        newActualDigitStarted = 1;
                }
                int newHasCome = 0;
                if (newActualDigitStarted > 0 && i == whichDigit) {
                    newHasCome = 1;
                }
                if (hasCome > 0) {
                    newHasCome = 1;
                }

                res += dp(newId, newTight, newHasCome, newActualDigitStarted);
            }
        }

        memo[id][tight][hasCome][actualDigitStarted] = res;
        return res;
    }

    private long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd (b, a % b);
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

}