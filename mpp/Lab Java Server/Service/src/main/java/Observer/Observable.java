package Observer;

import Models.Caritate;

import java.io.Serializable;
import java.util.List;

public interface Observable extends Serializable {
    void getNotified(List<Caritate> list);
}
