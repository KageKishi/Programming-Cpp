
/*7.Implement an application in Java to display and navigate Menu about “Phone Setting”  */
import java.util.Scanner;
class PhoneSettingApp {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        char choice;
        PhoneSettingApp app = new PhoneSettingApp();
        do {
            app.Menu();
            System.out.println("Enter Your choice: ");
            choice = sc.nextLine().charAt(0);
            switch(choice) {   
                case '1' -> {
                    boolean inGeneral = true;
                    while (inGeneral) {
                        app.General();
                        System.out.print("Enter your choice: ");
                        char gen = sc.nextLine().charAt(0);
                        switch(gen) {
                            case '1' -> { 
                                boolean inAbout = true;
                                while (inAbout) {
                                    app.About();
                                    System.out.println("");
                                    char back = sc.nextLine().charAt(0);
                                    if (back == '0') {
                                        inAbout = false; 
                                    }
                                }
                            }
                            case '2' -> {
                                boolean inUpdate = true;
                                while (inUpdate) {
                                    app.Softwareupdate();
                                    System.out.println("");
                                    char back = sc.nextLine().charAt(0);
                                    if (back == '0') {
                                        inUpdate = false;
                                    }
                                }
                            }
                            case '3' -> {
                                boolean inStorage = true;
                                while(inStorage){
                                app.NoFeature();
                                System.out.println("");
                                char back = sc.nextLine().charAt(0);
                                if(back == '0'){
                                    inStorage = false;
                                }
                                }
                            }
                            case '0' -> inGeneral = false;
                            default -> System.out.println("Please enter a valid choice");
                        }
                    }
                }

                case '2' -> {
                    boolean inWiFi = true;
                    app.WiFi();
                    while(inWiFi){
                        System.out.println("");
                        char wifi = sc.nextLine().charAt(0);
                        switch(wifi){
                            case '1' -> {
                                app.networks();
                                app.Back();
                            }
                            case '0' -> {inWiFi = false;
                                break;
                            }
                            default -> System.out.println("Please enter a valid option!");
                        }
                    }
                }
                case '3', '4', '5', '6' -> {
                    app.NoFeature();
                    app.Back();
                }
                default -> System.out.println("Please choose a valid option: ");
            }
        } while (choice != '0');
        if (choice == '0') {
            System.out.println("Goodbye!!");
        }
    }

    public void Menu() {
        System.out.println("Phone Setting: ");
        System.out.println("1. General          >");
        System.out.println("2. Wi-Fi            >");
        System.out.println("3. Bluetooth        >");
        System.out.println("4. Mobile Data      >");
        System.out.println("5. Hospot           >");
        System.out.println("6. Notification     >");
        System.out.println("0. Quit");
    }
    public void General() {
        System.out.println("General: ");
        System.out.println("1. About            >");
        System.out.println("2. Software update  >");
        System.out.println("3. Storage          >");
        System.out.println("0. Back             >");
    }
    public void About() {
        System.out.println("General > About: ");
        System.out.println("Name           iPhone");
        System.out.println("Model          IXs");
        System.out.println("Version        18.5");
        System.out.println("0.Back");
    }
    public void Softwareupdate() {
        System.out.println("General > Software Update: ");
        System.out.println("======================");
        System.out.println("Software is up to date");
        System.out.println("======================");
        System.out.println("0.Back");
    }
    public void WiFi() {
        System.out.println("Wi-Fi: ");
        System.out.println("Status             On");
        System.out.println("Network            I-Coffee");
        System.out.println("1. Other networks  >");
        System.out.println("0.Back ");
    }
    public void networks() {
        System.out.println("Wi-Fi  > Other networks: ");
        System.out.println("Bayon Coffee             *****");
        System.out.println("Angkor Coffee            **");
        System.out.println("Brown Coffee             ****");
        System.out.println("Koi                      *");
        System.out.println("0.Back");
    }
    public void NoFeature() {
        System.out.println("Title: ");
        System.out.println("=============================");
        System.out.println("This Feature is not available");
        System.out.println("=============================");
        System.out.println("0. Back");
    }
    public void Back() {
        System.out.print("Press 0 to go back: ");
        while (sc.nextLine().charAt(0) != '0') {
            System.out.print("Press 0 to go back: ");
        }
    }
}
