//import java.io.BufferedInputStream;
//import java.io.FileInputStream;
//import java.io.FileNotFoundException;
//import java.io.IOException;
//import java.util.zip.ZipEntry;
//import java.util.zip.ZipInputStream;
//
//
//public class Test {
//
//	/**
//	 * @param args
//	 * @throws IOException 
//	 */
//	public static void main(String[] args) throws IOException {
//		String srcFile = "C:/Users/yumikoy/Documents/word.zip";
//		
//		System.out.println("Hello World");
//		ZipInputStream in = new ZipInputStream(new BufferedInputStream(new FileInputStream( srcFile ) ) );
//		 ZipEntry zipEntry;
//		int entryNum = 0;
//		zipEntry = in.getNextEntry();
////		System.out.println(zipEntry);
//		 try {
//		 while( (zipEntry = in.getNextEntry()) != null){
//		 entryNum++;
//			System.out.println(zipEntry);
//		 }
//		 } catch (IOException e) {
//		 }
//
//	}
//
//	
//	
//	
//	
//	import java.io.BufferedInputStream;
//	import java.io.BufferedOutputStream;
//	import java.io.File;
//	import java.io.FileInputStream;
//	import java.io.FileNotFoundException;
//	import java.io.FileOutputStream;
//	import java.io.IOException;
//	import java.util.zip.ZipEntry;
//	import java.util.zip.ZipInputStream;
//
//	//コマンドライン第1引数に指定されたZIPファイルを第2引数に指定された
//	//ディレクトリに解凍する。
//	//コマンドライン第1引数：[解凍するZIPファイルのパス]
//	//コマンドライン第a2引数：[解凍先ディレクトリのパス]
//	//注意! ZIPファイルにエントリされているファイル名に日本語が含まれている場合は、
//	//IllegalArgumentExceptionが発生します。
//	public class UnzipFile {
//
//	      public static void main(String[] args) {
//	            
//	            System.out.println("--処理開始--");
//	            
//	            //コマンドライン引数が入力されているかチェックを行う
//	            if(args.length < 2)
//	            {
//	                  System.out.println("コマンドライン引数を指定してください");
//	                  return;
//	            }
//	            
//	            ZipInputStream in = null;      //ZIPファイル読込み用ストリーム
//	            BufferedOutputStream out = null;      //解凍ファイル出力用ストリーム
//	            
//	            try
//	            {
//	                  //コンストラクタの引数には、読み込むZIPファイルのパスを指定する
//	                  in = new ZipInputStream(new BufferedInputStream(new FileInputStream(args[0])));
//	                  
//	                  ZipEntry zipEntry = null;      //ZIPファイルから取り出したエントリを格納する変数
//	                  int data = 0;      //読込んだバイトを格納する変数
//	                  
//	                  //ZIPファイルの次のエントリの先頭にストリームを移動する
//	                  //ZIPファイルの終端に達したらNULLが返却されるのでループを抜ける
//	                  while( (zipEntry = in.getNextEntry()) != null )
//	                  {
//	                        //圧縮されているファイルのパスを標準出力に表示する
//	                        System.out.println(zipEntry.getName());            
//	                        
//	                        //ZIPファイルにディレクトリ構成で圧縮されている場合を考慮して、
//	                        //出力先ディレクトリ以下に子ディレクトリを作成しておく
//	                        //これをやらないとエラーになります。
//	                        new File(args[1] + "\\" + zipEntry.getName()).getParentFile().mkdirs();
//	                        
//	                        //ZIPファイル内のエントリをファイルに出力するストリームを生成する
//	                        out = new BufferedOutputStream(new FileOutputStream(args[1] + "\\" + zipEntry.getName()));
//	                        
//	                        //1バイトずつ、エントリから読み込んで、展開先ファイルに出力する
//	                        while( (data = in.read()) != -1 )
//	                        {
//	                              out.write(data);
//	                        }
//	                        
//	                        //現在のZIPエントリを閉じる
//	                        in.closeEntry();
//	                        
//	                        //出力ストリームを閉じる
//	                        out.close();
//	                        out = null;
//	                  }
//	                  
//	            }
//	            //読み込み対象ファイルが存在しなかった場合
//	            catch(FileNotFoundException e)
//	            {
//	                  System.out.println(e);
//	            }
//	            //入出力エラー()が発生した場合
//	            catch(IOException e)
//	            {
//	                  System.out.println(e);
//	            }
//	            //その他例外が発生した場合
//	            catch(Exception e)
//	            {
//	                  System.out.println(e);
//	                  e.printStackTrace();
//	            }
//	            //例外発生時にも確実にリソースが開放されるように
//	            //close()の呼び出しはfinallyブロックで行う。
//	            finally
//	            {
//	                  if(in != null)
//	                  {
//	                        try
//	                        {
//	                              in.close();
//	                        }catch(Exception e){ System.out.println(e); }
//	                  }
//	                  
//	                  if(out != null)
//	                  {
//	                        try
//	                        {
//	                              out.close();
//	                        }catch(Exception e){ System.out.println(e); }
//	                  }
//	            }
//	            
//	            System.out.println("--処理終了--");
//
//	      }
//	}
//	
//	
//	
//}
