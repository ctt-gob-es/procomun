package com.emergya.agrega2.odes.test;

import java.sql.Timestamp;
import java.util.Date;

import org.apache.commons.lang3.RandomStringUtils;
import org.apache.commons.lang3.RandomUtils;

public class DataFactoryUtil {

    // public static String[] ciudades = {};

    private static String[] comunidades = { "Andalucía", "Aragón", "Asturias", "Islas Baleares", "Canarias",
            "Cantabria", "Castilla-La Mancha", "Castilla y León", "Cataluña", "Extremadura", "Galicia", "La Rioja",
            "Comunidad de Madrid", "Navarra", "País Vasco", "Región de Murcia", "Comunidad Valenciana", "Ceuta",
            "Melilla" };

    private static String[] provincias = { "Vitoria", "Albacete", "Alicante", "Almería", "Ávila", "Badajoz",
            "Palma de Mallorca", "Barcelona", "Burgos", "Cáceres", "Cádiz", "Castellón", "Ciudad Real", "Córdoba",
            "Coruña", "Cuenca", "Gerona", "Granada", "Guadalajara", "San Sebastián", "Huelva", "Huesca", "Jaén",
            "León", "Lérida", "Logroño", "Lugo", "Madrid", "Málaga", "Murcia", "Pamplona", "Orense", "Oviedo",
            "Palencia", "Las Palmas", "Pontevedra", "Salamanca", "Santa Cruz de Tenerife", "Santander", "Segovia",
            "Sevilla", "Soria", "Tarragona", "Teruel", "Toledo", "Valencia", "Valladolid", "Bilbao", "Zamora",
            "Zaragoza", "Ceuta", "Melilla" };

    private static String[] telefonos = { "693178871", "108354487", "107786589", "490046971", "803033496", "458210127",
            "045881979", "506258506", "021681009", "351768867", "654549958", "836376178", "771452225", "802484623",
            "060357008", "291394610", "264190016", "929495399", "034973181", "532411655", "530734622", "062820591",
            "728251979", "668364175", "545114085", "175458964", "052716267", "101081749", "907262026", "166670691",
            "325354984", "497086077", "404489689", "213457019", "958534538", "760185516", "803580210", "454050315",
            "164153590", "728639155", "970796747", "254601085", "445493269", "166506916", "604247448", "451681704",
            "796174437", "936944723", "864693002", "790307313", "393405363", "517944948", "529870913", "596457196",
            "641251213", "476046148", "394811770", "288173321", "581100009", "846172360", "133417015", "146279307",
            "309564051", "625504538", "630826355", "521272143", "085306080", "993829235", "246238748", "951574106",
            "520737576", "574026229", "722452566", "065660431", "152108150", "377049826", "536038893", "593715409",
            "134507425", "582788307", "989618770", "457450684", "207806259", "934706804", "584844308", "780883926",
            "758541428", "626966750", "819296533", "976735567", "531493990", "248590249", "976940386", "138797167",
            "293084455", "547652959", "829557124", "506274983", "045704584", "405531794" };

    private static String[] dnis = { "39583307P", "82113592G", "94219788N", "70122557L", "98023535L", "92160759N",
            "28523714B", "23639279V", "78577210X", "80887986E", "92758054C", "06255255Z", "27916679S", "31276339L",
            "77380089Q", "68451143S", "82174408P", "89034632E", "03697620W", "30229148H", "03246936A", "64500726D",
            "36970259J", "16931578J", "41860235M", "76013943R", "91206424Q", "98432866L", "12312455A", "57592875R",
            "32945393D", "99783506F", "70893387G", "09370968D", "25955197L", "65975634L", "12235488V", "04491598C",
            "22413976Q", "09584303L" };

    private static String[] nombres = { "Jin del Carmen", "Jacqueline", "Kendall", "Daquan", "Kiara", "Pandora",
            "Kirestin", "Carol", "Walter", "Adrienne del Carmen", "Michael de la Vega", "Chandler", "Jerry", "Ryder",
            "Burke de la Vega", "Unity", "Diana", "Sybill", "Cullen", "Risa", "Walter", "Charde", "Kiara", "Nasim",
            "Caleb", "Anne", "Lucas del Carmen", "Brock", "Echo de la Vega", "Ashely", "Kirk", "Blair", "Hadassah",
            "Phyllis", "Clinton", "Haviva", "Amber", "Nicole", "Echo", "Zeph", "Chloe", "Quinn", "Leigh", "Amy",
            "Jillian", "Ishmael", "Lucian", "Katelyn", "Irene", "Grace", "Aretha", "Knox", "Montana", "Nero", "Lee",
            "Camilla", "Axel", "Jaden", "Sonia", "Donovan", "Elizabeth", "Ulric", "Alan del Carmen", "Valentine",
            "Faith", "Sloane", "Daphne", "Brady", "April", "Ivor", "Belle", "Malachi", "Abbot", "Jessamine del Carmen",
            "Raphael de la Vega", "Zeus", "Piper", "Baker", "Ivory", "Olivia", "Chaney", "Dieter", "Veronica",
            "Shelby", "Lisandra", "Dante", "Dane", "Veda", "Rhea", "Kathleen", "Len", "Sasha", "Michael", "Barclay",
            "Yoko", "August", "Chadwick", "María del Carmen" };

    private static String[] apellidos = { "Beck", "Mckay", "Collier", "Kirk", "Rosales", "Garner", "Cameron",
            "Castaneda", "Wheeler", "Ward", "Morin", "Rutledge", "Arnold", "Juarez", "Walker", "Richmond", "Chambers",
            "Beck", "Eaton", "Mcknight", "Miles", "Hays", "Myers", "Clements", "Burnett", "Chandler", "Buckner",
            "Burris", "Spencer", "Suarez", "Massey", "Underwood", "English", "Hays", "Mack", "Weaver", "Sherman",
            "Webb", "Curry", "Sears", "Pena", "Sutton", "Bauer", "Shaffer", "Conway", "Brooks", "Riggs", "Swanson",
            "Sheppard", "Stevenson", "Vinson", "Hebert", "Neal", "Marquez", "Dunlap", "Snider", "Molina", "Burnett",
            "Reid", "Bell", "Aguilar", "Carlson", "Dale", "Aguilar", "Whitfield", "Rodgers", "Barr", "Wiley", "Dorsey",
            "Smith", "Holmes", "Jacobson", "Lancaster", "Witt", "Kelly", "Bowen", "Mendoza", "Glover", "Ramos",
            "Montgomery", "Murphy", "Horn", "Villarreal", "Colon", "Casey", "Workman", "Copeland", "Spears", "Chen",
            "Schmidt", "Booth", "Atkinson", "Mccall", "Wise", "Hood", "Cervantes", "Pratt", "Craig", "Humphrey" };

    public static String getComunidad() {
        final int size = comunidades.length;
        final int pos = RandomUtils.nextInt(0, size);
        return comunidades[pos];
    }

    public static String getProvincia() {
        final int size = provincias.length;
        final int pos = RandomUtils.nextInt(0, size);
        return provincias[pos];
    }

    public static String getTelefono() {
        final int size = telefonos.length;
        final int pos = RandomUtils.nextInt(0, size);
        return telefonos[pos];
    }

    public static String getDni() {
        final int size = dnis.length;
        final int pos = RandomUtils.nextInt(0, size);
        return dnis[pos];
    }

    public static String getNombre() {
        final int size = nombres.length;
        final int pos = RandomUtils.nextInt(0, size);
        return nombres[pos];
    }

    public static String getApellido() {
        final int size = apellidos.length;
        final int pos = RandomUtils.nextInt(0, size);
        return apellidos[pos];
    }

    public static String getRandomString(int size) {
        return RandomStringUtils.randomAlphabetic(size);
    }

    public static Date getRandomDate() {
        long beginTime = Timestamp.valueOf("1980-01-01 00:00:00").getTime();
        long endTime = Timestamp.valueOf("2013-12-31 00:58:00").getTime();
        long diff = endTime - beginTime + 1;
        return new Date(beginTime + (long) (Math.random() * diff));
    }
}
