import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

// Interface NhapXuat
interface NhapXuat {
    int TIEN_THUE_BAO_HANG_THANG = 3000;
    int MUC_TRAN = 400000;

    void nhap();

    void xuat();
}

// Lớp ThueBao
class ThueBao {
    protected String maThueBao;
    protected String chuThueBao;    
    protected String diaChi;

    public ThueBao() {
    }

    public ThueBao(String maThueBao, String chuThueBao, String diaChi) {
        this.maThueBao = maThueBao;
        this.chuThueBao = chuThueBao;
        this.diaChi = diaChi;
    }

    public void nhapThongTin() {
        Scanner scanner =new Scanner(System.in);
        System.out.print("nhap ma thue bao: ");
        maThueBao = scanner.nextLine();
        System.out.print("nhap chu thue bao: ");
        chuThueBao = scanner.nextLine();
        System.out.print("Nhap dia chi: ");
        diaChi = scanner.nextLine();
    }

    public void xuatThongTin() {
        System.out.println("ma thue bao"+maThueBao);
        System.out.println("chu thue bao: " + chuThueBao);
        System.out.println("dia chi: " + diaChi);
    }
    // sử dụng get Mathuebao để sử dụng vào mục đích sau 
    // getthuebao trong tìm kiếm và xuất thông tin về mã thuê bao thỏa mãn 
    //không thể bỏ đi vì nó đóng vai trò quan trọng trong việc sắp xếp và tìm kiếm thuê bao dựa trên mã thuê bao
    /*getMaThueBao() cung cấp một giao diện công khai (public interface) để truy cập thuộc tính 
    maThueBao từ bên ngoài lớp ThueBao. Điều này là cần thiết để các phần khác của chương trình, 
    đặc biệt là trong trường hợp này là các hàm sắp xếp và tìm kiếm, có thể truy xuất và sử dụng 
    thông tin mã thuê bao một cách chính xác mà không cần vi phạm nguyên tắc đóng gói (encapsulation) của lớp.
     Việc sử dụng getter (như getMaThueBao()) là một thực tiễn lập trình tốt để đảm bảo tính bảo trì,
      khả năng mở rộng và khả năng tái sử dụng của mã. Nó cho phép bạn thay
     đổi triển khai bên trong lớp ThueBao mà không ảnh hưởng đến các phần khác của chương trình phụ thuộc vào nó. */
    public String getMaThueBao() {
        return maThueBao;
    }
}

// Lớp ThueBaoTheoDungLuong
class ThueBaoTheoDungLuong extends ThueBao implements NhapXuat {
    private int dungLuong;

    public ThueBaoTheoDungLuong() {
    }

    public ThueBaoTheoDungLuong(String maThueBao, String chuThueBao, String diaChi, int dungLuong) {
        super(maThueBao, chuThueBao, diaChi);
        this.dungLuong = dungLuong;
    }

    @Override
    public void nhap() {
        Scanner scanner = new Scanner(System.in);
        nhapThongTin();
        System.out.print("nhap dung luong su dung (MB): ");
        dungLuong = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        /* Enter sau khi nhập số nguyên. Ký tự \n (newline) đó vẫn còn nằm trong bộ đệm nhập liệu của Scanner.
         Nếu bạn không xóa nó đi (dùng scanner.nextLine()), thì trong lần gọi scanner.nextLine() kế tiếp (nếu có) nó sẽ đọc luôn \n và coi đó là một chuỗi rỗng.
          Điều này sẽ gây lỗi nếu bạn mong đợi nhận được đầu vào văn bản khác sau scanner.nextInt().
         Nên, scanner.nextLine() dùng ở đây để loại bỏ ký tự newline còn dư. */
    }

    @Override
    public void xuat() {
        xuatThongTin();
        long tienCuoc = tinhTienCuoc();
        System.out.println("dung luong su dung: " + dungLuong + " MB");
        System.out.println("tien cuoc: " + tienCuoc + " dong");
    }

    public long tinhTienCuoc() {
        long tienCuoc = NhapXuat.TIEN_THUE_BAO_HANG_THANG + dungLuong * 40;
        if (tienCuoc > NhapXuat.MUC_TRAN) {
            tienCuoc = NhapXuat.MUC_TRAN;
        }
        return tienCuoc;
    }
}
public class ktra1 {
    public static void main(String[] args) {
        ArrayList<ThueBaoTheoDungLuong> danhSachThueBao = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);

        // Nhập và xuất thông tin danh sách thuê bao
        int n;
        System.out.print("nhap so thue bao: ");
        n = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        for (int i = 0; i < n; i++) {
            ThueBaoTheoDungLuong thueBao = new ThueBaoTheoDungLuong();
            thueBao.nhap();
            danhSachThueBao.add(thueBao);
        }
        System.out.println("\ndanh sach thue bao:");
        for (ThueBaoTheoDungLuong thueBao : danhSachThueBao) {
            thueBao.xuat();
            System.out.println("------------------");
        }


        // Sắp xếp danh sách theo mã thuê bao
        Collections.sort(danhSachThueBao, Comparator.comparing(ThueBao::getMaThueBao));
        System.out.println("\ndanh sach thue bao sau khi xap sep:");
        for (ThueBaoTheoDungLuong thueBao : danhSachThueBao) {
            thueBao.xuat();
            System.out.println("------------------");
        }

        // Tìm kiếm thuê bao theo mã
        System.out.print("\nnhap ma thue bao can tim: ");
        String maCanTim = scanner.nextLine();
        boolean found = false;
        for (ThueBaoTheoDungLuong thueBao : danhSachThueBao) {
            if (thueBao.getMaThueBao().equals(maCanTim)) {
                System.out.println("\nthong tin thue bao:");
                thueBao.xuat();
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("khong tim thay thue bao co ma " + maCanTim);
        }
        //xoa thue bao theo ma
        System.out.print("\nnhap ma thue bao can xoa: ");
        String maCanxoa = scanner.nextLine();
        boolean test = false;
        for (ThueBaoTheoDungLuong thueBao : danhSachThueBao) {
            if (thueBao.getMaThueBao().equals(maCanxoa)) {
                danhSachThueBao.remove(maCanxoa);
                found = true;
                break;
            }
        }
        if (!test) {
            System.out.println("khong tim thay thue bao co ma " + maCanxoa);
        }
        System.out.println("\ndanh sach thue bao:");
        for (ThueBaoTheoDungLuong thueBao : danhSachThueBao) {
            thueBao.xuat();
            System.out.println("------------------");
        }

    }
}