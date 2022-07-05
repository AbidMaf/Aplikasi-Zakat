#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <sstream>
#include <iomanip>
#include <limits>
#include <stdlib.h>
#include <string>

using namespace std;

MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;

bool loop = true;

void viewFitrah();
void viewMal();
void viewSearch();
void addFitrah();
void addMal();
void updateFitrah();
void updateMal();
void delFitrah();
void delMal();
void dashboard();
int getFitrahOption();
int getOption();
int mainGetOption();

connection()
{
    try
    {
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "localhost", "root", NULL, "cpp_db", 0, NULL, 0);
    }
    catch(string e)
    {
        cout << e;
    }
}

void viewFitrah()
{
    system("cls");
    if(conn)
    {
        int qstate = mysql_query(conn, "SELECT *, CASE WHEN jenis = 'uang' THEN jml_jiwa * 25000 WHEN jenis = 'beras' THEN jml_jiwa * 2.5 ELSE 'none' END AS total FROM fitrah;");
        if(!qstate)
        {
            res = mysql_store_result(conn);
            cout << left;
            cout << "|==============================================================|\n";
            cout << "|" << setw(3) << "Id" <<"|" << setw(25) << "Nama" <<"|" << setw(3) << "Rt" <<"|" << setw(4) << "Jiwa"
                 << "|" << setw(5) << "Jenis" <<"|" << setw(8) << "Total" << "|" << setw(8) << "Sedekah" << "|" << endl;
            cout << "|==============================================================|\n";
            while(row = mysql_fetch_row(res))
            {
                cout << left;
                cout << "|" << setw(3) << row[0] <<"|" << setw(25) << row[1]
                     << "|" << setw(3) << row[2] <<"|" << setw(4) << row[3]
                     <<"|" << setw(5) << row[4] << "|" << setw(8) << row[6]
                     << "|" << setw(8) << row[5] << "|" << endl;
            }
            cout << "|==============================================================|\n";
            while(true)
            {
                cout << "1. Cari\n";
                cout << "2. Keluar\n";
                cout << "Pilih Aksi: ";
                char opt;
                cin >> opt;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                if(opt == '1')
                {
                    string keySearch;
                    cout << "Masukkan nama pezakat  : ";
                    getline(cin, keySearch);
                    stringstream ss_data1;
                    ss_data1 << "SELECT *, CASE WHEN jenis = 'uang' THEN jml_jiwa * 25000 WHEN jenis = 'beras' THEN jml_jiwa * 2.5 ELSE 'none' END AS total FROM fitrah WHERE nama LIKE '%" << keySearch << "%';";
                    string sql_data1 = ss_data1.str();
                    const char* q_data1 = sql_data1.c_str();
                    mysql_query(conn, q_data1);
                    res = mysql_store_result(conn);
                    if(!mysql_num_rows(res) < 1)
                    {
                        cout << left;
                        cout << "|==============================================================|\n";
                        cout << "|" << setw(3) << "Id" <<"|" << setw(25) << "Nama" <<"|" << setw(3) << "Rt" <<"|" << setw(4) << "Jiwa"
                             << "|" << setw(5) << "Jenis" <<"|" << setw(8) << "Total" << "|" << setw(8) << "Sedekah" << "|" << endl;
                        cout << "|==============================================================|\n";
                        while(row = mysql_fetch_row(res))
                        {
                            cout << left;
                            cout << "|" << setw(3) << row[0] <<"|" << setw(25) << row[1]
                                 << "|" << setw(3) << row[2] <<"|" << setw(4) << row[3]
                                 <<"|" << setw(5) << row[4] << "|" << setw(8) << row[6]
                                 << "|" << setw(8) << row[5] << "|" << endl;
                        }
                        cout << "|==============================================================|\n";
                    }
                }
                else if(opt == '2')
                {
                    mainGetOption();
                }
                else
                {
                    cout << "Data tidak ditemukan\n";
                }
            }
        }
    }
    else
    {
        cout << "not connected";
    }
}

void viewMal()
{
    char opt;
    system("cls");
    if(conn)
    {
        int qstate = mysql_query(conn, "SELECT *, (penghasilan * 2.5) / 100 AS total FROM mal; ");
        if(!qstate)
        {
            res = mysql_store_result(conn);
            cout << left;
            cout << "|===========================================================|\n";
            cout << "|" << setw(3) << "Id" <<"|" << setw(25) << "Nama"
                 << "|" << setw(11) << "Penghasilan" <<"|" << setw(8) << "Total"
                 << "|" << setw(8) << "Sedekah" << "|" << endl;
            cout << "|===========================================================|\n";
            while(row = mysql_fetch_row(res))
            {
                cout << left;
                cout << "|" << setw(3) << row[0] <<"|" << setw(25) << row[1]
                     << "|" << setw(11) << row[2] <<"|" << setw(8) << row[4]
                     << "|" << setw(8) << row[3] << "|" << endl;
            }
            cout << "|===========================================================|\n\n";

            while(true)
            {
                cout << "1. Cari\n";
                cout << "2. Keluar\n";
                cout << "Pilih Aksi: ";
                char opt;
                cin >> opt;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                if(opt == '1')
                {
                    string keySearch;
                    cout << "Masukkan nama pezakat  : ";
                    getline(cin, keySearch);
                    stringstream ss_data1;
                    ss_data1 << "SELECT *, (penghasilan * 2.5) / 100 AS total FROM mal WHERE nama LIKE '%" << keySearch << "%';";
                    string sql_data1 = ss_data1.str();
                    const char* q_data1 = sql_data1.c_str();
                    mysql_query(conn, q_data1);
                    res = mysql_store_result(conn);
                    if(!mysql_num_rows(res) < 1)
                    {
                        cout << left;
                        cout << "|===========================================================|\n";
                        cout << "|" << setw(3) << "Id" <<"|" << setw(25) << "Nama"
                             << "|" << setw(11) << "Penghasilan" <<"|" << setw(8) << "Total"
                             << "|" << setw(8) << "Sedekah" << "|" << endl;
                        cout << "|===========================================================|\n";
                        while(row = mysql_fetch_row(res))
                        {
                            cout << left;
                            cout << "|" << setw(3) << row[0] <<"|" << setw(25) << row[1]
                                 << "|" << setw(11) << row[2] <<"|" << setw(8) << row[4]
                                 << "|" << setw(8) << row[3] << "|" << endl;
                        }
                        cout << "|===========================================================|\n\n";
                    }
                }
                else if(opt == '2')
                {
                    mainGetOption();
                }
                else
                {
                    cout << "Data tidak ditemukan\n";
                }
            }
        }
    }
    else
    {
        cout << "not connected";
    }
}

void addFitrah(string jenis)
{
    system("cls");
    cout << "=========================================";
    cout << "\n          TAMBAH ZAKAT FITRAH            ";
    cout << "\n=========================================\n\n";
    string nama;
    int qstate = 0;
    double sisa;
    int rt, jml_jiwa, bayar;
    double total;
    if(conn)
    {
        cout << "Masukkan nama          : ";
        getline(cin, nama);
        cout << "Masukkan Rt            : ";
        cin >> rt;
        cout << "Masukkan jumlah jiwa   : ";
        cin >> jml_jiwa;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if(jenis == "uang")
        {
            total = jml_jiwa * 25000;
        }
        else if(jenis == "beras")
        {
            total = jml_jiwa * 2.5;
        }
        cout << "Jumlah yang harus dibayarkan sebesar Rp" << total << endl;
        while(true)
        {
            cout << "Jumlah yang dibayar    : ";
            cin >> bayar;
            sisa = bayar - total;
            if(sisa > 0)
            {
                char opt;
                cout << "Sisa sebesar Rp" << sisa << ". Sedekahkan? (y/n) " << endl;
                cin >> opt;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                if(opt == 'n')
                {
                    sisa = 0;
                }
                else
                {
                    sisa = sisa;
                }
                stringstream ss;
                ss << "INSERT INTO fitrah(nama, rt, jml_jiwa, jenis, sedekah) values('" <<
                   nama << "' , '" <<
                   rt << "' , '" <<
                   jml_jiwa << "' , '" <<
                   jenis << "' , '" <<
                   (int)sisa << "')";
                string query = ss.str();
                const char* q = query.c_str();
                qstate = mysql_query(conn, q);
                if(qstate == 0)
                {
                    cout << "Data Berhasil" << endl;
                }
                else
                {
                    cout << "Data gagal dimasukkan : \n" << mysql_error(conn) << endl;
                }
                while(true)
                {
                    cout << "Lanjut menambah data? (y/n)";
                    cin >> opt;
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    if(opt == 'n')
                    {
                        cout << opt;
                        mainGetOption();
                    }
                    else if(opt == 'y')
                    {
                        system("cls");
                        addFitrah(jenis);
                    }
                    else {}
                }
            }
            else
            {
                cout << "Jumlah yang dibayarkan kurang\n\n";
            }
        }
    }
}

void addMal()
{
    system("cls");
    cout << "=========================================";
    cout << "\n             TAMBAH ZAKAT MAL            ";
    cout << "\n=========================================\n\n";
    string nama;
    int qstate = 0;
    int penghasilan, bayar;
    double sisa, total;
    if(conn)
    {
        while(loop)
        {
            cout << "Masukkan nama          : ";
            getline(cin, nama);
            cout << "Masukkan Penghasilan   : ";
            cin >> penghasilan;
            total = (penghasilan * 2.5) / 100;
            cout << "Jumlah yang harus dibayarkan sebesar Rp" << total << endl;
            while(true)
            {
                cout << "Jumlah yang dibayar    : ";
                cin >> bayar;
                sisa = bayar - total;
                char opt;
                if(sisa >= 0)
                {
                    here:
                    cout << "Sisa sebesar Rp" << sisa << ". Sedekahkan? (y/n) " << endl;
                    cin >> opt;
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    if(opt == 'n')
                    {
                        sisa = 0;
                    }
                    else if(opt == 'y')
                    {
                        sisa = sisa;
                    }
                    else{
                        goto here;
                    }
                    stringstream ss;
                    ss << "INSERT INTO mal(nama, penghasilan, sedekah) values('" <<
                       nama << "' , '" <<
                       penghasilan << "' , '" <<
                       (int)sisa << "')";
                    string query = ss.str();
                    const char* q = query.c_str();
                    qstate = mysql_query(conn, q);
                    if(qstate == 0)
                    {
                        cout << "Data Berhasil Ditambah" << endl;
                    }
                    else
                    {
                        cout << "Data gagal dimasukkan : \n" << mysql_error(conn) << endl;
                    }
                    while(true)
                    {
                        cout << "Lanjut menambah data? (y/n)";
                        cin >> opt;
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        if(opt == 'n')
                        {
                            cout << opt;
                            mainGetOption();
                        }
                        else if(opt == 'y')
                        {
                            system("cls");
                            addMal();
                        }
                        else {}
                    }
                }
                else
                {
                    cout << "Jumlah yang dibayarkan kurang\n\n";
                }
            }
        }
    }
}

void updateFitrah(string jenis)
{
    system("cls");
    string id, nama_n;
    int rt_n;

    stringstream ss_data;
    ss_data << "SELECT * FROM fitrah WHERE jenis = '" << jenis << "'";
    string sql_data = ss_data.str();
    const char* q_data = sql_data.c_str();
    int qstate = mysql_query(conn, q_data);
    if(!qstate)
    {
        res = mysql_store_result(conn);
        cout << left;
        cout << "|==============================================================|\n";
        cout << "|" << setw(3) << "Id" <<"|" << setw(25) << "Nama"
             << "|" << setw(3) << "Rt" <<"|" << setw(4) << "Jiwa"
             << "|" << setw(5) << "Jenis" <<"|" << setw(8) << "Sedekah" << "|" << endl;
        cout << "|==============================================================|\n";
        while(row = mysql_fetch_row(res))
        {
            cout << left;
            cout << "|" << setw(3) << row[0] <<"|" << setw(25) << row[1]
                 << "|" << setw(3) << row[2] <<"|" << setw(4) << row[3]
                 << "|" << setw(5) << row[4] <<"|" << setw(8) << row[5] << endl;
        }
        cout << "|==============================================================|\n";
    }

    cout << endl;
    while(loop)
    {
        cout << "Pilih ID data yang ingin diubah    : ";
        getline(cin, id);

        stringstream ss_data1;
        ss_data1 << "SELECT * FROM fitrah WHERE id = '" << id << "' AND jenis = '" << jenis << "'";
        string sql_data1 = ss_data1.str();
        const char* q_data1 = sql_data1.c_str();
        mysql_query(conn, q_data1);
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);

        if(!mysql_num_rows(res) < 1)
        {
            cout << "\nData yang tersimpan\n";
            cout << "Nama   : " << row[1] << endl;
            cout << "Rt     : " << row[2] << endl;
            cout << "Jiwa   : " << row[3] << endl;
            cout << "Sedekah: " << row[4] << endl << endl;

            cout << "Data Baru\n";
            cout << "Nama   : ";
            getline(cin, nama_n);
            cout << "Rt     : ";
            cin >> rt_n;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            stringstream ss;
            ss << "UPDATE fitrah SET nama = '" <<
               nama_n << "' , rt = '" << rt_n <<"' WHERE id = '" <<
               id << "'";
            string query = ss.str();
            const char* q = query.c_str();
            qstate = mysql_query(conn, q);
            if(qstate == 0)
            {
                cout << "Data Berhasil Diubah" << endl;
            }
            else
            {
                cout << "Data gagal dimasukkan : \n" << mysql_error(conn) << endl;
                cin.get();
            }
            while(loop)
            {
                cout << "Lanjut mengubah data? (y/n)";
                char opt;
                cin >> opt;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                if(opt == 'n')
                {
                    cout << opt;
                    mainGetOption();
                }
                else if(opt == 'y')
                {
                    system("cls");
                    cout << jenis;
                    updateFitrah(jenis);
                }
                else {}
            }
        }
        else
        {
            cout << "Data tidak ditemukan\n\n";
        }
    }
}

void updateMal()
{
    system("cls");
    string id, nama_n;

    if(conn)
    {
        int qstate = mysql_query(conn, "SELECT *, (penghasilan * 2.5) / 100 AS total FROM mal; ");
        if(!qstate)
        {
            res = mysql_store_result(conn);
            cout << left;
            cout << "|===========================================================|\n";
            cout << "|" << setw(3) << "Id" <<"|" << setw(25) << "Nama"
                 << "|" << setw(11) << "Penghasilan" <<"|" << setw(8) << "Total"
                 << "|" << setw(8) << "Sedekah" << "|" << endl;
            cout << "|===========================================================|\n";
            while(row = mysql_fetch_row(res))
            {
                cout << left;
                cout << "|" << setw(3) << row[0] <<"|" << setw(25) << row[1]
                     << "|" << setw(11) << row[2] <<"|" << setw(8) << row[4]
                     <<"|" << setw(8) << row[3] << "|" << endl;
            }
            cout << "|===========================================================|\n";
        }

        cout << endl;

        while(loop)
        {
            cout << "Pilih ID data yang ingin diubah    : ";
            getline(cin, id);

            stringstream ss_data;
            ss_data << "SELECT * FROM mal WHERE id = '" << id << "'";
            string sql_data = ss_data.str();
            const char* q_data = sql_data.c_str();

            mysql_query(conn, q_data);
            res = mysql_store_result(conn);
            row = mysql_fetch_row(res);
            if(!mysql_num_rows(res) < 1)
            {
                cout << "\nData yang tersimpan\n";
                cout << "Nama       : " << row[1] << endl;
                cout << "Penghasilan: " << row[2] << endl;
                cout << "Sedekah    : " << row[3] << endl << endl;

                cout << "Data Baru\n";
                cout << "Nama       : ";
                getline(cin, nama_n);

                stringstream ss;
                ss << "UPDATE mal SET nama = '" <<
                   nama_n << "' WHERE id = '" <<
                   id << "'";
                string query = ss.str();
                const char* q = query.c_str();
                qstate = mysql_query(conn, q);
                if(qstate == 0)
                {
                    cout << "Data Berhasil Diubah" << endl;
                }
                else
                {
                    cout << "Data gagal dimasukkan : \n" << mysql_error(conn) << endl;
                    cin.get();
                }
                while(true)
                {
                    cout << "Lanjut mengubah data? (y/n)";
                    char opt;
                    cin >> opt;
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    if(opt == 'n')
                    {
                        cout << opt;
                        mainGetOption();
                    }
                    else if(opt == 'y')
                    {
                        system("cls");
                        updateMal();
                    }
                    else {}
                }
            }
            else
            {
                cout << "Data tidak ditemukan\n\n";
            }
        }
    }
}

void delFitrah(string jenis)
{
    system("cls");
    int id;
    string nama_n;
    int rt_n;

    stringstream ss_data;
    ss_data << "SELECT * FROM fitrah WHERE jenis = '" << jenis << "'";
    string sql_data = ss_data.str();
    const char* q_data = sql_data.c_str();
    int qstate = mysql_query(conn, q_data);
    if(!qstate)
    {
        res = mysql_store_result(conn);
        cout << left;
        cout << "|==============================================================|\n";
        cout << "|" << setw(3) << "Id" <<"|" << setw(25) << "Nama"
             << "|" << setw(3) << "Rt" <<"|" << setw(4) << "Jiwa"
             << "|" << setw(5) << "Jenis" <<"|" << setw(8) << "Sedekah" << "|" << endl;
        cout << "|==============================================================|\n";
        while(row = mysql_fetch_row(res))
        {
            cout << left;
            cout << "|" << setw(3) << row[0] <<"|" << setw(25) << row[1]
                 << "|" << setw(3) << row[2] <<"|" << setw(4) << row[3]
                 << "|" << setw(5) << row[4] <<"|" << setw(8) << row[5] << endl;
        }
        cout << "|==============================================================|\n";
    }

    cout << endl;
    while(true)
    {
        cout << "Pilih ID data yang ingin diubah    : ";
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        stringstream ss_data1;
        ss_data1 << "SELECT * FROM fitrah WHERE id = '" << id << "'";
        string sql_data1 = ss_data1.str();
        const char* q_data1 = sql_data1.c_str();
        mysql_query(conn, q_data1);
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);

        if(!mysql_num_rows(res) < 1)
        {
            cout << "Data yang tersimpan\n";
            cout << "Nama   : " << row[1] << endl;
            cout << "Rt     : " << row[2] << endl;
            cout << "Jiwa   : " << row[3] << endl;
            cout << "Sedekah: " << row[4] << endl << endl;

            char opt;
            while(true)
            {
                cout << "Apakah anda yakin ingin menghapus? (y/n)";
                cin >> opt;
                if(opt == 'y')
                {
                    stringstream ss;
                    ss << "DELETE FROM fitrah WHERE id = '" <<
                       id << "'";
                    string query = ss.str();
                    const char* q = query.c_str();
                    qstate = mysql_query(conn, q);
                    if(qstate == 0)
                    {
                        cout << "\nData berhasil dihapus\n";
                    }
                    else
                    {
                        cout << "\nData gagal dihapuskan : \n" << mysql_error(conn) << endl;
                        cin.get();
                    }
                }
                else if(opt == 'n')
                {
                    cout << "Data batal dihapuskan\n";
                }
                else {}
                while(true)
                {
                    cout << "Lanjut menghapus data? (y/n)";
                    cin >> opt;
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    if(opt == 'n')
                    {
                        cout << opt;
                        mainGetOption();
                    }
                    else if(opt == 'y')
                    {
                        system("cls");
                        delFitrah(jenis);
                    }
                    else {}
                }
            }
        }
        else
        {
            cout << "Data tidak ditemukan\n\n";
        }
    }
}

void delMal()
{
    system("cls");
    int id;
    string nama_n;

    if(conn)
    {
        int qstate = mysql_query(conn, "SELECT *, (penghasilan * 2.5) / 100 AS total FROM mal; ");
        if(!qstate)
        {
            res = mysql_store_result(conn);
            cout << left;
            cout << "|===========================================================|\n";
            cout << "|" << setw(3) << "Id" <<"|" << setw(25) << "Nama"
                 << "|" << setw(11) << "Penghasilan" <<"|" << setw(8) << "Total"
                 << "|" << setw(8) << "Sedekah" << "|" << endl;
            cout << "|===========================================================|\n";
            while(row = mysql_fetch_row(res))
            {
                cout << left;
                cout << "|" << setw(3) << row[0] <<"|" << setw(25) << row[1]
                     << "|" << setw(11) << row[2] <<"|" << setw(8) << row[4]
                     <<"|" << setw(8) << row[3] << "|" << endl;
            }
            cout << "|===========================================================|\n";
        }

        cout << endl;

        while(loop)
        {
            cout << "Pilih ID data yang ingin dihapus   : ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            stringstream ss_data;
            ss_data << "SELECT * FROM mal WHERE id = '" << id << "'";
            string sql_data = ss_data.str();
            const char* q_data = sql_data.c_str();
            mysql_query(conn, q_data);
            res = mysql_store_result(conn);
            row = mysql_fetch_row(res);

            if(!mysql_num_rows(res) < 1)
            {
                cout << "Data yang tersimpan\n";
                cout << "Nama       : " << row[1] << endl;
                cout << "Penghasilan: " << row[2] << endl;
                cout << "Sedekah    : " << row[3] << endl << endl;

                char opt;
                while(true)
                {
                    cout << "Apakah anda yakin ingin menghapus? (y/n)";
                    cin >> opt;
                    if(opt == 'y')
                    {
                        stringstream ss;
                        ss << "DELETE FROM mal WHERE id = '" <<
                           id << "'";
                        string query = ss.str();
                        const char* q = query.c_str();
                        qstate = mysql_query(conn, q);
                        if(qstate == 0)
                        {
                            cout << "\nData berhasil dihapus\n";
                        }
                        else
                        {
                            cout << "\nData gagal dihapuskan : \n" << mysql_error(conn) << endl;
                            cin.get();
                        }
                    }
                    else if(opt == 'n')
                    {
                        cout << "Data batal dihapuskan\n";
                    }
                    else {}
                    while(true)
                    {
                        cout << "Lanjut menghapus data? (y/n)";
                        cin >> opt;
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        if(opt == 'n')
                        {
                            cout << opt;
                            mainGetOption();
                        }
                        else if(opt == 'y')
                        {
                            system("cls");
                            delMal();
                        }
                        else {}
                    }
                }
            }
            else
            {
                cout << "Data tidak ditemukan\n\n";
            }
        }
    }
}

void dashboard()
{
    system("cls");
    cout << "=========================================";
    cout << "\n             Dashboard                 ";
    cout << "\n=========================================\n\n";
    cout << "Banyak data yang tercatat: \n";
    if(conn)
    {
        string jenis[] = {"uang","beras"};
        int n = sizeof(jenis) / sizeof(jenis[0]);
        cout << "\t\t|\n";
        for(int i = 0; i < n; i++)
        {
            cout << "Fitrah (" << jenis[i] << ")\t| ";
            stringstream ss_data1;
            ss_data1 << "SELECT * FROM fitrah WHERE jenis = '" << jenis[i] << "'";
            string sql_data1 = ss_data1.str();
            const char* q_data1 = sql_data1.c_str();
            mysql_query(conn, q_data1);
            res = mysql_store_result(conn);
            row = mysql_fetch_row(res);
            for(int j = 0; j < mysql_num_rows(res); j++)
            {
                cout << "=";
            }
            cout << " (" << mysql_num_rows(res) << ")" << endl;
            cout << "\t\t|\n";
        }
        cout << "Mal\t\t| ";
        stringstream ss_data;
        ss_data << "SELECT * FROM mal";
        string sql_data = ss_data.str();
        const char* q_data = sql_data.c_str();
        mysql_query(conn, q_data);
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);
        for(int j = 0; j < mysql_num_rows(res); j++)
        {
            cout << "=";
        }
        cout << " (" << mysql_num_rows(res) << ")" << endl;
        cout << "\t\t|\n";
        system("pause");
        mainGetOption();
    }
}

int getFitrahOption(string pilih)
{
    char option;
    system("cls");
    cout << "=========================================";
    cout << "\n             PILIH JENIS                 ";
    cout << "\n=========================================";
    cout << "\n|            1. Uang                    |";
    cout << "\n|            2. Beras                   |";
    cout << "\n=========================================";
    cout << "\n             Pilih: ";
    while(true)
    {
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if(option == '1')
        {
            if(pilih == "add")
            {
                addFitrah("uang");
            }
            else if(pilih == "edit")
            {
                updateFitrah("uang");
            }
            else if(pilih == "del")
            {
                delFitrah("uang");
            }
            else if(pilih == "view")
            {
                viewFitrah();
            }
        }
        else if(option == '2')
        {
            if(pilih == "add")
            {
                addFitrah("beras");
            }
            else if(pilih == "edit")
            {
                updateFitrah("beras");
            }
            else if(pilih == "del")
            {
                delFitrah("beras");
            }
            else if(pilih == "view")
            {
                viewFitrah();
            }
        }
        else
        {
            cout << "Pilihan tidak tersedia\n";
        }
        return option;
    }
}

int getOption(string pilih)
{
    char option;
    system("cls");

    cout << "=========================================";
    cout << "\n             PILIH JENIS                 ";
    cout << "\n=========================================";
    cout << "\n|            1. Fitrah                  |";
    cout << "\n|            2. Mal                     |";
    cout << "\n=========================================";
    bool loop = true;
    while(true)
    {
        cout << "\n             Pilih: ";
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if(option == '1')
        {
            if(pilih == "add")
            {
                getFitrahOption(pilih);
            }
            else if(pilih == "edit")
            {
                getFitrahOption(pilih);
            }
            else if(pilih == "del")
            {
                getFitrahOption("del");
            }
            else if(pilih == "view")
            {
                viewFitrah();
                loop = false;
            }
        }
        else if(option == '2')
        {
            if(pilih == "add")
            {
                addMal();
            }
            else if(pilih == "edit")
            {
                updateMal();
            }
            else if(pilih == "del")
            {
                delMal();
            }
            else if(pilih == "view")
            {
                viewMal();
            }
        }
        else
        {
            cout << "Pilihan tidak tersedia\n";
        }
    }
    return option;
}

int mainGetOption()
{
    char option;
    system("cls");

    cout << "=========================================";
    cout << "\n  SELAMAT DATANG DI APLIKASI ZAKATNATIK  ";
    cout << "\n=========================================";
    cout << "\n|            1. Tambah Data             |";
    cout << "\n|            2. Ubah Data               |";
    cout << "\n|            3. Hapus Data              |";
    cout << "\n|            4. Lihat Data              |";
    cout << "\n|            5. Dashboard               |";
    cout << "\n|            6. Selesai                 |";
    cout << "\n=========================================";
    cout << "\n             Pilih(1-5): ";
    while(loop = true)
    {
        cin >> option;
        switch(option)
        {
        case '1':
            getOption("add");
            break;
        case '2':
            getOption("edit");
            break;
        case '3':
            getOption("del");
            break;
        case '4':
            getOption("view");
            break;
        case '5':
            dashboard();
            break;
        case '6':
            mysql_close(conn);
            exit(1);
            break;
        default:
            cout << "Pilihan tidak tersedia\n";
        }
    }
    return option;
}

int main()
{
    int option;
    try
    {
        connection();
        if(conn)
        {
            cout << "Database terhubung\n";
            mainGetOption();
        }
        else
        {
            cout << "Database tidak dapat terhubung. Harap periksa ulang";
            cout << mysql_errno(conn);
        }
    }
    catch(int e)
    {
        cout << e;
    }

    return 0;
}
