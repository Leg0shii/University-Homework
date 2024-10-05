package de.legoshi.util;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
@AllArgsConstructor
public class Message {

    private MessageType messageType;
    private Object sender;
    private int time;

}
