import java.io.*;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;

/**
 * Created by nikosmyrtakes on 21/06/2017.
 */
public class MainActivity {

	static TreeMap<String,String> dataset = new TreeMap<>();

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = null;


		File file;
		System.out.println("Give the input of file: ");
		while(true){
			input = br.readLine();
			Path path = FileSystems.getDefault().getPath(input);
			boolean fExists = Files.exists(path);
			boolean fIsFile = Files.isRegularFile(path);
			if(fExists && fIsFile)
				break;
			System.out.println("File Not Found. Try Again: ");
		}


		file = new File(input);

		try {

			BufferedReader bufferedInputStream = new BufferedReader(new FileReader(file));
			String line;
			int counter = 0;

			while((line = bufferedInputStream.readLine()) != null){
				line = bufferedInputStream.readLine();
				String[] firstword = line.split("\\|",2);
				dataset.put(firstword[0], "|"+firstword[1]);
			}

			File fileOutput = new File(input+"Sorted.txt");
			BufferedWriter bw = new BufferedWriter(new FileWriter(fileOutput));

			for(String key : dataset.keySet()){
				String lineOut = key + dataset.get(key);
				bw.write(lineOut);
				bw.newLine();
			}

			bw.close();

			System.out.println("FILE CREATED");

		} catch (IOException e) {
			System.out.println("File not found !");
		}

	}

}
