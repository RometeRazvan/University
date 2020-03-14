package Tools;

import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;

public class PropertiesLoader {

    private String fileName;
    private InputStream inputStream;

    public PropertiesLoader(String fileName) {
        this.fileName = fileName;
        this.inputStream = getClass().getClassLoader().getResourceAsStream(this.fileName);
    }

    public Properties getProperties() throws IOException {
        Properties prop = new Properties();
        prop.load(this.inputStream);
        return prop;
    }

}
