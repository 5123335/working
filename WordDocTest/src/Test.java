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
//	//�R�}���h���C����1�����Ɏw�肳�ꂽZIP�t�@�C�����2�����Ɏw�肳�ꂽ
//	//�f�B���N�g���ɉ𓀂���B
//	//�R�}���h���C����1�����F[�𓀂���ZIP�t�@�C���̃p�X]
//	//�R�}���h���C����a2�����F[�𓀐�f�B���N�g���̃p�X]
//	//����! ZIP�t�@�C���ɃG���g������Ă���t�@�C�����ɓ��{�ꂪ�܂܂�Ă���ꍇ�́A
//	//IllegalArgumentException���������܂��B
//	public class UnzipFile {
//
//	      public static void main(String[] args) {
//	            
//	            System.out.println("--�����J�n--");
//	            
//	            //�R�}���h���C�����������͂���Ă��邩�`�F�b�N���s��
//	            if(args.length < 2)
//	            {
//	                  System.out.println("�R�}���h���C���������w�肵�Ă�������");
//	                  return;
//	            }
//	            
//	            ZipInputStream in = null;      //ZIP�t�@�C���Ǎ��ݗp�X�g���[��
//	            BufferedOutputStream out = null;      //�𓀃t�@�C���o�͗p�X�g���[��
//	            
//	            try
//	            {
//	                  //�R���X�g���N�^�̈����ɂ́A�ǂݍ���ZIP�t�@�C���̃p�X���w�肷��
//	                  in = new ZipInputStream(new BufferedInputStream(new FileInputStream(args[0])));
//	                  
//	                  ZipEntry zipEntry = null;      //ZIP�t�@�C��������o�����G���g�����i�[����ϐ�
//	                  int data = 0;      //�Ǎ��񂾃o�C�g���i�[����ϐ�
//	                  
//	                  //ZIP�t�@�C���̎��̃G���g���̐擪�ɃX�g���[�����ړ�����
//	                  //ZIP�t�@�C���̏I�[�ɒB������NULL���ԋp�����̂Ń��[�v�𔲂���
//	                  while( (zipEntry = in.getNextEntry()) != null )
//	                  {
//	                        //���k����Ă���t�@�C���̃p�X��W���o�͂ɕ\������
//	                        System.out.println(zipEntry.getName());            
//	                        
//	                        //ZIP�t�@�C���Ƀf�B���N�g���\���ň��k����Ă���ꍇ���l�����āA
//	                        //�o�͐�f�B���N�g���ȉ��Ɏq�f�B���N�g�����쐬���Ă���
//	                        //��������Ȃ��ƃG���[�ɂȂ�܂��B
//	                        new File(args[1] + "\\" + zipEntry.getName()).getParentFile().mkdirs();
//	                        
//	                        //ZIP�t�@�C�����̃G���g�����t�@�C���ɏo�͂���X�g���[���𐶐�����
//	                        out = new BufferedOutputStream(new FileOutputStream(args[1] + "\\" + zipEntry.getName()));
//	                        
//	                        //1�o�C�g���A�G���g������ǂݍ���ŁA�W�J��t�@�C���ɏo�͂���
//	                        while( (data = in.read()) != -1 )
//	                        {
//	                              out.write(data);
//	                        }
//	                        
//	                        //���݂�ZIP�G���g�������
//	                        in.closeEntry();
//	                        
//	                        //�o�̓X�g���[�������
//	                        out.close();
//	                        out = null;
//	                  }
//	                  
//	            }
//	            //�ǂݍ��ݑΏۃt�@�C�������݂��Ȃ������ꍇ
//	            catch(FileNotFoundException e)
//	            {
//	                  System.out.println(e);
//	            }
//	            //���o�̓G���[()�����������ꍇ
//	            catch(IOException e)
//	            {
//	                  System.out.println(e);
//	            }
//	            //���̑���O�����������ꍇ
//	            catch(Exception e)
//	            {
//	                  System.out.println(e);
//	                  e.printStackTrace();
//	            }
//	            //��O�������ɂ��m���Ƀ��\�[�X���J�������悤��
//	            //close()�̌Ăяo����finally�u���b�N�ōs���B
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
//	            System.out.println("--�����I��--");
//
//	      }
//	}
//	
//	
//	
//}
