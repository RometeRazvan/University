using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using LabCSharp.Domain;

namespace LabCSharp
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            String connectionString = "URI=file:/Users/test/database/tasks.db,Version=3";
            using (IDbConnection cnn = new )
            {
                
            }
        }

        public string LoadConnectionString(string id = "taskDB")
        {
            return ConfigurationManager.ConnectionStrings[id].ConnectionString;
        }
    }
}