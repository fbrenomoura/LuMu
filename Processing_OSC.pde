import oscP5.*;
import netP5.*;
import processing.video.*;

OscP5 oscP5;
NetAddress myRemoteLocation;
Movie video;

String msgOSC = null;

void setup() {
  size(800, 600);
  frameRate(30);
  
  oscP5 = new OscP5(this,8333);
  myRemoteLocation = new NetAddress("127.0.0.1",8333);

  
  video = new Movie(this, "totoro.mov");
  video.loop();
}

void draw() {
  
  image(video, 80, 200);
  
  if(mousePressed){
    if(mouseX>300 && mouseX<300+80 && mouseY>100 && mouseY<110+60) {
      video.play();
    }
  
  }
  
  if(mousePressed){
    if(mouseX>400 && mouseX<400+80 && mouseY>100 && mouseY<110+60) {
      video.pause();
    }
  
  }
    
    
}

void movieEvent(Movie m) {
  m.read();
}

void oscEvent(OscMessage theOscMessage) {
  /* print the address pattern and the typetag of the received OscMessage */
  print("### received an osc message.");
  print(" addrpattern: "+theOscMessage.addrPattern());
  println(" typetag: "+theOscMessage.typetag());
  msgOSC = (" addrpattern: "+theOscMessage.addrPattern());
}
