/**
 * Created with IntelliJ IDEA.
 * User: Enayat
 * Date: 4/8/14
 * Time: 1:34 PM
 * To change this template use File | Settings | File Templates.
 */
public class vCardParser {
    String value;
    //vCardParser(String v){value.v;}

    public String fullName(String value){
        String []words=value.split(" ");
        String str="";
        for(int i=0;i<words.length;i++){
            if(words[i].startsWith("FN:")){

                if(words[i].length()>8){
                    if(words[i].substring(words[i].indexOf("FN")+3,words[i].indexOf("FN")+8).toUpperCase().equals("EMAIL"))
                        return str;
                    else
                        str=words[i].substring(words[i].indexOf("FN")+3,words[i].length());
                }else{
                    return str;
                }
                i++;
                while(!words[i].startsWith("EMAIL") && !words[i].startsWith("ORG:") && !words[i].startsWith("END:") && !words[i].startsWith("VERSION:") && !words[i].startsWith("N:")){
                    str+=" "+words[i];
                    if(i<words.length-1)
                        i++;
                    else
                        break;
                }
            }
        }
        return str;
    }
    public String name(String value){
        String []words=value.split(" ");
        String str="";
        for(int i=0;i<words.length;i++){
            if(words[i].startsWith("N:")){
                if(words[i].length()>2)
                    str=words[i].substring(words[i].indexOf("N:")+2,words[i].length());
                i++;
                while(!words[i].startsWith("EMAIL") && !words[i].startsWith("ORG:") && !words[i].startsWith("END:") && !words[i].startsWith("VERSION:") && !words[i].startsWith("FN:")){
                    str+=" "+words[i];
                    if(i<words.length-1)
                        i++;
                    else
                        break;
                }
            }
        }
        return str;
    }
    public String version(String value){
        String []words=value.split(" ");
        String str="";
        for(int i=0;i<words.length;i++){
            if(words[i].startsWith("VERSION:")){
                if(words[i].length()>8)
                    str=words[i].substring(words[i].indexOf("VERSION:")+8,words[i].length());
                i++;
                while(!words[i].startsWith("EMAIL") && !words[i].startsWith("ORG:") && !words[i].startsWith("END:") && !words[i].startsWith("N:") && !words[i].startsWith("FN:")){
                    str+=" "+words[i];
                    if(i<words.length-1)
                        i++;
                    else
                        break;
                }
            }
        }
        return str;
    }
    public String organization(String value){
        String []words=value.split(" ");
        String str="";
        for(int i=0;i<words.length;i++){
            if(words[i].startsWith("ORG:")){

                if(words[i].length()>4)
                    str=words[i].substring(words[i].indexOf("ORG:")+4,words[i].length());

                i++;
                while(!words[i].startsWith("EMAIL") && !words[i].startsWith("VERSION:") && !words[i].startsWith("END:") && !words[i].startsWith("N:") && !words[i].startsWith("FN:")){
                    str+=" "+words[i];
                    if(i<words.length-1)
                        i++;
                    else
                        break;
                }
            }
        }
        return str;
    }
    public String email(String value){
        String []words=value.split(" ");
        String str="";
        for(int i=0;i<words.length;i++){
            if(words[i].startsWith("EMAIL")){
                if(words[i].length()>23){
                    if(words[i].substring(words[i].indexOf("EMAIL")+20,23).toUpperCase().equals("ORG"))
                        return str;
                    else
                        str=words[i].substring(words[i].indexOf("EMAIL")+20,words[i].length());
                }else{
                    return str;
                }
                i++;
                while(!words[i].startsWith("ORG:") && !words[i].startsWith("VERSION:") && !words[i].startsWith("END:") && !words[i].startsWith("N:") && !words[i].startsWith("FN:")){
                    str+=" "+words[i];
                    i++;
                }

            }
        }
        return str;
    }
    public static void main(String[] args) {
        vCardParser v1=new vCardParser();
        String v="*";
        System.out.println(v1.fullName(v));
        System.out.println(v1.name(v));
        System.out.println(v1.email(v));
        System.out.println(v1.organization(v));
    }


}
