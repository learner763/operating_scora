#include <WiFi.h>  // For ESP32
#include <ESPAsyncWebServer.h>
#include <String>
#include <iostream>
#include <ESP32Servo.h>
const char *ssid = "ESP_AP";  // WiFi Name
const char *password = "12345678";  // WiFi Password
Servo myservo;
WiFiServer server(80);  // Start a web server on port 80


String htmlPage = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0-beta3/css/all.min.css">
    <style>
        body{
            margin: 0%;
        }
        
        html{
            scroll-behavior: smooth;
        }
        .a{
            display: flex;
            position: fixed;
            top: 0%;
            background-color: black;
            width: 100%;
            justify-content: space-around;
            align-items: center;
            font-weight: bolder;
            color: white;
            font-size: 20px;
            flex-wrap: wrap;
            border: white solid;
            border-width: 0px 0px 1px 0px ;
        }
        .a label{
            cursor: pointer;
            margin: 3px;
        }
        .b{
            display: flex;
            width: 100%;
            background-color: #191960;
            justify-content: space-around;
            align-items: center;
            flex-wrap: wrap;
            flex-direction: row;
            border: white solid;
            border-width: 0px 0px 1px 0px ;

            
        }
        #img1{
            width: 300px;   
            margin-top: 40px;   
              
        }
        
        #h1{
            font-size: 40px;
            margin-top:40px;
        }
        
        .c{
            display: flex;
            width: 100%;
            background-color: darkblue;
            justify-content: space-around;
            align-items: center;
            flex-wrap: wrap;
            flex-direction: column;
            border: white solid;
            border-width: 0px 0px 1px 0px ;
            color: white;
            
        }
        #c1, #e1,#f1,#g1,#h1{
            font-size: 30px;
            color: lime;
            font-weight: bolder;
            margin-top: 10px;
            margin-bottom: 10px;

        }
        #c2,#e2,#e3,#f2,#f3,#h2,#g2,.g div div label{
            font-size: 20px;
            color: white;
            margin-right: 15px;
            margin-left: 15px;
            margin-bottom: 10px;


        }
        .e{
            display: flex;
            width: 100%;
            background-color: darkblue;
            justify-content: space-around;
            align-items: center;
            flex-wrap: wrap;
            flex-direction: column;
            border: white solid;
            border-width: 0px 0px 1px 0px ;
            color: white;
        }
        .e div,.f div,.h div{
            display: flex;
            justify-content: space-around;
            align-items: center;
            flex-wrap: wrap;
            flex-direction: row;
            
        }
        .e div label,.f div label,.h div label{
            font-size: 20px;
            color: lime;
            font-weight: bolder;
            margin: 10px;
        }
        .e div button,.f button,.h button{
            font-size: 20px;
            border-radius: 5px;
            margin: 10px;
            cursor: pointer;
            background-color: white;
            font-weight: bold;
        }
        .e div button,.h button{
            color: darkblue;
            border-width: 1px;
            border: darkblue solid;

        }
        .f button{
            color: #191960;
            border: #191960 solid;

        }
        .e div button:hover,.f button:hover,.h button:hover{
            color: white;
            transition: all 0.3s ease-in-out; 
            border: white solid;  
         
        }
        .e div button:hover,.h button:hover{
            background-color: darkblue;
        }
        .f button:hover{
            background-color: #191960;
        }
        .e div input[type="checkbox"]{
            cursor: pointer;
            width: 20px;
            height: 20px;
        }
        .e div input[type="checkbox"]:checked{
            accent-color: darkblue;
        }

        .f div input[type="number"],.h div input[type="number"]{
            cursor: pointer;
            font-size: 20px;
            border-radius: 5px;
            border: none;
        }
        .f,.h{
            display: flex;
            width: 100%;
            justify-content: space-around;
            align-items: center;
            flex-direction: column;
            border: white solid;
            border-width: 0px 0px 1px 0px ;
        }
        .h{
            background-color: darkblue;
        }
        .f{
            background-color:#191960;
        }
        .g{
            display: flex;
            background-color: #191960;
            flex-direction: column;
            justify-content: space-around;
            align-items: center;
            border: white solid;
            border-width: 0px 0px 1px 0px ;
        }
        .g img{
            width:350px;
            
        }
        .g div div label{
            width: 300px;
            border-radius: 8px;
            background-color: white;
            color: #191960;
            padding: 3px;

        }
        
        .g div div{
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;
        }
        .g div{
            display: flex;
            flex-wrap: wrap;
            justify-content: space-around;
            align-items: center;
        }
        @media (max-width:850px)
        {
            .a label{font-size: 15px;}
            .b #h1{font-size: 24px;margin-top: 40px;}
            .b #p{font-size: 18px;}
            .c #c1{font-size: 18px;}
            .e #e1{font-size: 18px;}
            .f #f1{font-size: 18px;}
            .g #g1{font-size: 18px;}
            .h #h1{font-size: 18px;}
            .c #c2{font-size: 15px;}
            .f #f2{font-size: 15px;}
            .f #f3{font-size: 15px;}
            .e #e2{font-size: 15px;}
            .e #e3{font-size: 15px;}
            .g #g2{font-size: 15px;}
            .h #h2{font-size: 15px;}
            .e div label{font-size: 15px;}
            .f div label,.h div label{font-size: 15px;}
            .g div div label{font-size: 15px;}
            .f div input[type="number"],.h div input[type="number"]{font-size: 15px;}
            .e div button,.f button,.h button{font-size: 15px;}
            #img1{width: 200px;margin-top: 10px;}

            .g div div img{width: 250px;}
        }
    </style>
</head>

<body>
    <div class="a">
        <label >About</label>
        <label >Kinematics</label>
        <label >Operation</label>
        <label >Specifications</label>
    </div>
    <div id="About">
        <div class="b">
            <h1 id="h1" style="color: lime;font-weight: bolder;">
                SCORA ER-14 ROBOT
            <p id="p" style="color: white;">4-DOF Robotic Arm for Kinematics and Control</p>
            </h1>
            <img id="img1" src="scora.png"  alt="">
        </div>

        <div class="c">
            <label id="c1">Overview</label>
            <label id="c2">
                This is web-based user interface for operating SCORA ER-14 which is a 4-degree-of-freedom (DOF) robotic arm designed for educational
                and industrial applications.It features a robust mechanical structure with precise 
                joint articulation, enabling users to perform forward and inverse kinematics calculations
                for motion planning. The robot is commonly used in real-world automation techniques.
            </label>
        </div>
    </div>
    <div id="Kinematics">

    </div>
    <div id="Operation">
        <div class="g">
            <label id="g1">Wireless Setup</label>
            <label id="g2">The robot is programmed through ESP micro-controller and is driven wirelessly.Perform following steps to get started.</label>
            <div>
                <div >
                    <img src="esp.png" alt="">
                    <label >Power ON the ESP by connecting to laptop.</label>
                </div>
                <div>
                    <img src="wifi.png" alt="">
                    <label >Connect your device to ESP's Wifi Network.</label>

                </div>
                <div>
                    <img src="browser.png" alt="">
                    <label >To access this web page,Navigate to <code>http://192.168.4.1/</code>.  </label>

                </div>
            </div>
        </div>
        <div class="e">
            <label id="e1">Get Started</label>
            <label id="e3">Precision control at your fingertips – Operate the SCORA robot with ease!</label>
            <label id="e2"> Trigger a 10-degree rotation or 5-cm translation for individual robot joints.</label>
            <div>
                <label>Joint 1:</label>
                <button >Start</button>               
                <label ><input type="checkbox" >Clock-wise</label>
            </div>
            <div>
                <label>Joint 2:</label>
                <button >Start</button>               
                <label ><input type="checkbox" >Clock-wise</label>

            </div>
            <div>
                <label>Joint 3:</label>
                <button >Start</button>               
                <label ><input type="checkbox" >Downward</label>


            </div>
            <div>
                <label>Joint 4:</label>
                <button >Start</button>               
                <label ><input type="checkbox" >Clock-wise</label>

            </div>
                
        </div>
        <div class="f">
            <label  id="f1">Forward Kinematics</label>
            <label id="f2">Provide joint poses as input and change the position of the end effector.</label>
            <label id="f3">Positive values correspond to Anti-Clockwise rotation and Downward translation.</label>
            <div>
                <label>Joint 1:</label>
                <input  type="number" placeholder="Angle(deg)">                
            </div>
            <div>
                <label>Joint 2:</label>
                <input  type="number" placeholder="Angle(deg)">                
            </div>
            <div>
                <label>Joint 3:</label>
                <input  type="number" placeholder="Translation(cm)">                
            </div>
            <div>
                <label>Joint 4:</label>
                <input  type="number" placeholder="Angle(deg)">                
              
            </div>
            <button id="submit">Submit</button>
        </div>

        <div class="h">
            <label id="h1">Inverse Kinematics</label>
            <label id="h2">Provide coordinate positions of the
                end effector with respect to base frame of the robot
                and see joints moving accordingly.</label>
            <div>
                <label>Position X:</label>
                <input  type="number" placeholder="Coordinate(cm)">                
            </div>
            <div>
                <label>Position Y:</label>
                <input  type="number" placeholder="Coordinate(cm)">                
            </div>
            <div>
                <label>Position Z:</label>
                <input  type="number" placeholder="Coordinate(cm)">                
            </div>
            <button id="submit_inverse">Submit</button>
        </div>
    </div>
    <div id="Specification">

    </div>

    <script>
        document.addEventListener("DOMContentLoaded",()=>
    {
        let ids=["#About","#Kinematics","#Operation","#Specification"]
        let icons=document.querySelectorAll(".a label")
        let checks=document.querySelectorAll(".e div input")
        let joints=document.querySelectorAll(".e div button")
        let directions=["A","A","U","A"]
        let requests=["M1_ON","M2_ON","M3_ON","M4_ON"]
        let end_pos=document.querySelectorAll(".h div input")
        let submit_inverse=document.getElementById("submit_inverse")
        let joint_angles=document.querySelectorAll(".f div input")
        let submit=document.getElementById("submit")
        for(let i=0;i<checks.length;i++)
        {
            checks[i].addEventListener("change",()=>
            {
                if(checks[i].checked)
                {
                    if(i!=2){directions[i]="C"}
                    else{directions[i]="D"}
                }
                else{
                    if(i!=2){directions[i]="A"}
                    else{directions[i]="U"}
                }
            })
        }
        
        icons[0].style.color="lime"
        
        for(let i=0;i<icons.length;i++)
        {
            icons[i].addEventListener("click",()=>
            {
                for(let j=0;j<icons.length;j++)
                {
                    icons[j].style.color="white"
                }
                icons[i].style.color="lime"
                window.location.hash=ids[i]
            })
        }
        
        
        
        submit.addEventListener("click",()=>
        {
            let angles=[]
            for(let i=0;i<joint_angles.length;i++)
            {
                angles.push(joint_angles[i].value)
            }
        
            fetch(`/forward_kinematics?j1=${angles[0]}&j2=${angles[1]}&j3=${angles[2]}&j4=${angles[3]}`)
            .then(response=>console.log("Command sent: "+angles))
            .catch(error=>console.error("Error:",error))
        })
        submit_inverse.addEventListener("click",()=>
        {
            let theta1=Math.acos((end_pos[0].value*end_pos[0].value+end_pos[1].value*end_pos[1].value-(270*270+230*230))/(2*270*230))
            let theta2=Math.atan2(230*Math.sin(theta1)+end_pos[1].value*270+end_pos[1].value*230*Math.cos(theta1),end_pos[0].value*270+end_pos[0].value*230*Math.cos(theta1)-end_pos[1].value*230*Math.sin(theta1))
            let trans1=270-end_pos[2].value
            console.log(theta1)
            console.log(theta2)
            console.log(trans1)
            fetch(`/inverse_kinematics?j1=${theta1*57.3}&j2=${theta2*57.3}&j3=${trans1}&j4=0`)
            .then(response=>console.log("Command sent: "+theta1+" "+theta2+" "+trans1))
            .catch(error=>console.error("Error:",error))
        })
        for(let i=0;i<joints.length;i++)
        {
            joints[i].addEventListener("click",()=>
            {
                fetch(`/${requests[i]}${directions[i]}`)
                .then(response=>console.log("Command sent: "+requests[i]+directions[i]))
                .catch(error=>console.error("Error:",error))
            })
        }
    }
    )
    
    
    </script>
</body>
</html>
)rawliteral";
#define M1_ENCODER_A 32
#define M1_ENCODER_B 35  
#define M3_ENCODER_A 33
#define M3_ENCODER_B 34
#define CPR 1024      // Counts Per Revolution (adjust based on encoder model)

volatile int M1_encoderCount = 0;
int lastStateA1;
volatile int M3_encoderCount = 0;
int lastStateA3;



void IRAM_ATTR readEncoder1() {
    int stateA1 = digitalRead(M1_ENCODER_A);
    int stateB1 = digitalRead(M1_ENCODER_B);

    if (stateA1 != lastStateA1) {
        if (stateB1 != stateA1) {
            M1_encoderCount++;
        } else {
            M1_encoderCount--;
        }
    }
    lastStateA1 = stateA1;
}
void IRAM_ATTR readEncoder3() {
    int stateA3 = digitalRead(M3_ENCODER_A);
    int stateB3 = digitalRead(M3_ENCODER_B);

    if (stateA3 != lastStateA3) {
        if (stateB3 != stateA3) {
            M3_encoderCount++;
        } else {
            M3_encoderCount--;
        }
    }
    lastStateA3 = stateA3;
}


void setup() {
    Serial.begin(9600);
    WiFi.softAP(ssid, password);  // Create ESP's own WiFi network
    server.begin();  // Start web server
    //Motor1
    #define M1_REN 25
    #define M1_LEN 27
    #define M1_RPWM 26
    #define M1_LPWM 14
    //Motor2
    #define M2_REN 16
    #define M2_LEN 4
    #define M2_RPWM 17
    #define M2_LPWM 5
     //Motor3
    #define M3_REN 18
    #define M3_LEN 15
    #define M3_RPWM 19
    #define M3_LPWM 13
     //Motor4
    //Encoder1
    pinMode(M1_ENCODER_A, INPUT_PULLUP);
    pinMode(M1_ENCODER_B, INPUT_PULLUP);
    lastStateA1 = digitalRead(M1_ENCODER_A);
    attachInterrupt(digitalPinToInterrupt(M1_ENCODER_A), readEncoder1, CHANGE);
    //Encoder3
    pinMode(M3_ENCODER_A, INPUT_PULLUP);
    pinMode(M3_ENCODER_B, INPUT_PULLUP);
    lastStateA3 = digitalRead(M3_ENCODER_A);
    attachInterrupt(digitalPinToInterrupt(M3_ENCODER_A), readEncoder3, CHANGE);
    //Encoder4
    myservo.attach(23);

    int array[12]={13,15,19,18,5,17,4,16,14,25,26,27};
    for(int i=0;i<12;i++)
    {
        pinMode(array[i],OUTPUT);
        digitalWrite(array[i],LOW);
    }
}

void loop() {
    WiFiClient client = server.available();  // Check for new connections
    if (!client) return;

    // Wait until the client sends a request
    while (!client.available()) delay(1);

    String request = client.readStringUntil('\r');  // Read the request
    client.flush();

    
    // Check if browser requested LED ON or OFF
    if (request.indexOf("/M1_ON") != -1) {
        digitalWrite(M1_REN,HIGH);
        digitalWrite(M1_LEN,HIGH);
        float angle1 = (M1_encoderCount *360*1.07) / (165*1024);  
        int loop1=0;
        bool condition=angle1<10.0;
        if(request[10]=='C')
        {
            condition=angle1>-10.0;
        }
        while(condition)
        {
            angle1 = (M1_encoderCount *360) / (165*1024);
            Serial.println(angle1);
            if(request[10]=='A'){analogWrite(M1_RPWM,loop1);}//AntiClockwise
            else{analogWrite(M1_LPWM,loop1);}//ClockWise
            delay(50);
            loop1+=1;
        }
        digitalWrite(M1_REN,LOW);
        digitalWrite(M1_LEN,LOW);
        analogWrite(M1_LPWM,0);
        analogWrite(M1_RPWM,0);
        client.println("HTTP/1.1 204 No Content"); // No response body
    }
    if (request.indexOf("/M2_ON") != -1) {
        digitalWrite(M2_REN,HIGH);
        digitalWrite(M2_LEN,HIGH);
        int loop2=0;

        for(int i=0;i<255;i+=1)
        {
            if(request[10]=='C'){analogWrite(M2_RPWM,i);}//Clockwise
            else{analogWrite(M2_LPWM,i);}//AntiClockWise
            delay(30);
            Serial.println(request[10]);
            Serial.println(request);
            loop2+=1;
        }
        client.println("HTTP/1.1 204 No Content"); // No response body
    }
    if (request.indexOf("/M3_ON") != -1) {
        digitalWrite(M3_REN,HIGH);
        digitalWrite(M3_LEN,HIGH);
        int loop3=0;
        
        float trans1= (M3_encoderCount *360) / (160*1024*4.91);
        bool condition=trans1<5.0;  
        if(request[10]=='U')
        {
            condition=trans1>-5.0;
        }
        while(condition)
        {
            trans1 = (M3_encoderCount *360) / (160*1024*4.91);
            Serial.println(trans1);
            if(request[10]=='D'){analogWrite(M3_RPWM,loop3);condition=trans1<5.0;}//Down
            else{analogWrite(M3_LPWM,loop3);condition=trans1>-5.0;}//Up
            delay(50);
            loop3+=1;
        }
        digitalWrite(M3_REN,LOW);
        digitalWrite(M3_LEN,LOW);
        analogWrite(M3_RPWM,0);
        analogWrite(M3_LPWM,0);
        client.println("HTTP/1.1 204 No Content"); // No response body
    } 
    
    if (request.indexOf("/forward_kinematics") != -1) {
        String name_=request.substring(20,request.length());
        int e[4];
        int a[4];
        int ee=0;
        int aa=0;
        for(int i=0;i<name_.length();i++)
        {
            if(name_[i]=='=')
            {
                e[ee]=i;
                ee+=1;
            }
            if(name_[i]=='&')
            {
                a[aa]=i;
                aa+=1;    
            }
        }
        
        int j1=(name_.substring(e[0]+1,a[0])).toInt();
        int j2=(name_.substring(e[1]+1,a[1])).toInt();
        int j3=(name_.substring(e[2]+1,a[2])).toInt();
        int j4=(name_.substring(e[3]+1,a[3])).toInt();
        int loop5=0;
        float angle1 = (M1_encoderCount *360*1.07) / (165*1024);  
        float trans1= (M3_encoderCount *360) / (160*1024*4.91);

        Serial.println(j1);
        Serial.println(j2);
        Serial.println(j3);
        Serial.println(j4);
        
        bool condition1=angle1<j1;
        if(j1<0){condition1=angle1>j1;}
        bool condition2=trans1<j3;
        if(j3<0){condition2=trans1>j3;}
        bool condition=condition1 || condition2;
        while(condition)
        {
            angle1 = (M1_encoderCount *360*1.07) / (165*1024);
            trans1= (M3_encoderCount *360) / (160*1024*4.91);
            Serial.println(angle1);
            Serial.println(trans1);

            if(digitalRead(M1_LEN)!=HIGH){digitalWrite(M1_LEN,HIGH);}
            if(digitalRead(M1_REN)!=HIGH){digitalWrite(M1_REN,HIGH);}
            
            if(digitalRead(M3_LEN)!=HIGH){digitalWrite(M3_LEN,HIGH);}
            if(digitalRead(M3_REN)!=HIGH){digitalWrite(M3_REN,HIGH);}
            
            if(j1<0)
            {
                if(angle1>j1){analogWrite(M1_LPWM,loop5);}
                else{analogWrite(M1_LPWM,0);}
            }
            else
            {
                if(angle1<j1){analogWrite(M1_RPWM,loop5);}
                else{analogWrite(M1_RPWM,0);}
            }

            if(j3<0)
            {
                if(trans1>j3){analogWrite(M3_LPWM,loop5);}
                else{analogWrite(M3_LPWM,0);}
            }
            else
            {
                if(trans1<j3){analogWrite(M3_RPWM,loop5);}
                else{analogWrite(M3_RPWM,0);}
            }
            condition1=angle1<j1;
            if(j1<0){condition1=angle1>j1;}
            condition2=trans1<j3;
            if(j3<0){condition2=trans1>j3;}  
            condition=condition1 || condition2;  
            myservo.write(170);        
            delay(100);
            loop5+=1;
        }
        
            digitalWrite(M1_REN,LOW);
            digitalWrite(M1_LEN,LOW);
            digitalWrite(M2_REN,LOW);
            digitalWrite(M2_LEN,LOW);
            digitalWrite(M3_REN,LOW);
            digitalWrite(M3_LEN,LOW);
            
            analogWrite(M1_LPWM,0);
            analogWrite(M1_RPWM,0);
            analogWrite(M2_RPWM,0);
            analogWrite(M2_LPWM,0);
            analogWrite(M3_RPWM,0);
            analogWrite(M3_LPWM,0);
            delay(100);
        myservo.write(60);
        delay(30);
        condition1=angle1>0;
        if(j1<0){condition1=angle1<0;}
        condition2=trans1>0;
        if(j3<0){condition2=trans1<0;}
        condition=condition1 || condition2;
        while(condition)
        {
            angle1 = (M1_encoderCount *360*1.07) / (165*1024);
            trans1= (M3_encoderCount *360) / (160*1024*4.91);
            Serial.println(angle1);
            Serial.println(trans1);

            if(digitalRead(M1_LEN)!=HIGH){digitalWrite(M1_LEN,HIGH);}
            if(digitalRead(M1_REN)!=HIGH){digitalWrite(M1_REN,HIGH);}
            
            if(digitalRead(M3_LEN)!=HIGH){digitalWrite(M3_LEN,HIGH);}
            if(digitalRead(M3_REN)!=HIGH){digitalWrite(M3_REN,HIGH);}
            
            if(j1<0)
            {
                if(angle1<0){analogWrite(M1_RPWM,loop5);}
                else{analogWrite(M1_RPWM,0);}
            }
            else
            {
                if(angle1>0){analogWrite(M1_LPWM,loop5);}
                else{analogWrite(M1_LPWM,0);}
            }

            if(j3<0)
            {
                Serial.println("hah");
                if(trans1<0){analogWrite(M3_RPWM,loop5);Serial.println("hah1");}
                else{analogWrite(M3_RPWM,0);}
            }
            else
            {

                if(trans1>0){analogWrite(M3_LPWM,loop5);Serial.println("hah2");}
                else{analogWrite(M3_LPWM,0);}
            }
            condition1=angle1>0;
            if(j1<0){condition1=angle1<0;}
            condition2=trans1>0;
            if(j3<0){condition2=trans1<0;}  
            condition=condition1 || condition2;          
            delay(200);
            loop5+=1;
        myservo.write(60);
        delay(500);
        }
        
            digitalWrite(M1_REN,LOW);
            digitalWrite(M1_LEN,LOW);
            digitalWrite(M2_REN,LOW);
            digitalWrite(M2_LEN,LOW);
            digitalWrite(M3_REN,LOW);
            digitalWrite(M3_LEN,LOW);
            
            analogWrite(M1_LPWM,0);
            analogWrite(M1_RPWM,0);
            analogWrite(M2_RPWM,0);
            analogWrite(M2_LPWM,0);
            analogWrite(M3_RPWM,0);
            analogWrite(M3_LPWM,0);
            delay(100);
            

        client.println("HTTP/1.1 204 No Content"); // No response body
    }

    if (request.indexOf("/inverse_kinematics") != -1) {
        String name_=request.substring(20,request.length());
        int e[4];
        int a[4];
        int ee=0;
        int aa=0;
        for(int i=0;i<name_.length();i++)
        {
            if(name_[i]=='=')
            {
                e[ee]=i;
                ee+=1;
            }
            if(name_[i]=='&')
            {
                a[aa]=i;
                aa+=1;    
            }
        }
        
        int j1=(name_.substring(e[0]+1,a[0])).toInt();
        int j2=(name_.substring(e[1]+1,a[1])).toInt();
        int j3=(name_.substring(e[2]+1,a[2])).toInt();
        int j4=(name_.substring(e[3]+1,a[3])).toInt();
        int loop5=0;
        float angle1 = (M1_encoderCount *360*1.07) / (165*1024);  
        float trans1= (M3_encoderCount *360) / (160*1024*4.91);

        Serial.println(j1);
        Serial.println(j2);
        Serial.println(j3);
        Serial.println(j4);
        
        bool condition1=angle1<j1;
        if(j1<0){condition1=angle1>j1;}
        bool condition2=trans1<j3;
        if(j3<0){condition2=trans1>j3;}
        bool condition=condition1 || condition2;
        while(condition)
        {
            angle1 = (M1_encoderCount *360*1.07) / (165*1024);
            trans1= (M3_encoderCount *360) / (160*1024*4.91);
            Serial.println(angle1);
            Serial.println(trans1);

            if(digitalRead(M1_LEN)!=HIGH){digitalWrite(M1_LEN,HIGH);}
            if(digitalRead(M1_REN)!=HIGH){digitalWrite(M1_REN,HIGH);}
            
            if(digitalRead(M3_LEN)!=HIGH){digitalWrite(M3_LEN,HIGH);}
            if(digitalRead(M3_REN)!=HIGH){digitalWrite(M3_REN,HIGH);}
            
            if(j1<0)
            {
                if(angle1>j1){analogWrite(M1_LPWM,loop5);}
                else{analogWrite(M1_LPWM,0);}
            }
            else
            {
                if(angle1<j1){analogWrite(M1_RPWM,loop5);}
                else{analogWrite(M1_RPWM,0);}
            }

            if(j3<0)
            {
                if(trans1>j3){analogWrite(M3_LPWM,loop5);}
                else{analogWrite(M3_LPWM,0);}
            }
            else
            {
                if(trans1<j3){analogWrite(M3_RPWM,loop5);}
                else{analogWrite(M3_RPWM,0);}
            }
            condition1=angle1<j1;
            if(j1<0){condition1=angle1>j1;}
            condition2=trans1<j3;
            if(j3<0){condition2=trans1>j3;}  
            condition=condition1 || condition2;  
            myservo.write(170);        
            delay(100);
            loop5+=1;
        }
        
            digitalWrite(M1_REN,LOW);
            digitalWrite(M1_LEN,LOW);
            digitalWrite(M2_REN,LOW);
            digitalWrite(M2_LEN,LOW);
            digitalWrite(M3_REN,LOW);
            digitalWrite(M3_LEN,LOW);
            
            analogWrite(M1_LPWM,0);
            analogWrite(M1_RPWM,0);
            analogWrite(M2_RPWM,0);
            analogWrite(M2_LPWM,0);
            analogWrite(M3_RPWM,0);
            analogWrite(M3_LPWM,0);
            delay(100);
        myservo.write(60);
        delay(30);
        condition1=angle1>0;
        if(j1<0){condition1=angle1<0;}
        condition2=trans1>0;
        if(j3<0){condition2=trans1<0;}
        condition=condition1 || condition2;
        while(condition)
        {
            angle1 = (M1_encoderCount *360*1.07) / (165*1024);
            trans1= (M3_encoderCount *360) / (160*1024*4.91);
            Serial.println(angle1);
            Serial.println(trans1);

            if(digitalRead(M1_LEN)!=HIGH){digitalWrite(M1_LEN,HIGH);}
            if(digitalRead(M1_REN)!=HIGH){digitalWrite(M1_REN,HIGH);}
            
            if(digitalRead(M3_LEN)!=HIGH){digitalWrite(M3_LEN,HIGH);}
            if(digitalRead(M3_REN)!=HIGH){digitalWrite(M3_REN,HIGH);}
            
            if(j1<0)
            {
                if(angle1<0){analogWrite(M1_RPWM,loop5);}
                else{analogWrite(M1_RPWM,0);}
            }
            else
            {
                if(angle1>0){analogWrite(M1_LPWM,loop5);}
                else{analogWrite(M1_LPWM,0);}
            }

            if(j3<0)
            {
                Serial.println("hah");
                if(trans1<0){analogWrite(M3_RPWM,loop5);Serial.println("hah1");}
                else{analogWrite(M3_RPWM,0);}
            }
            else
            {

                if(trans1>0){analogWrite(M3_LPWM,loop5);Serial.println("hah2");}
                else{analogWrite(M3_LPWM,0);}
            }
            condition1=angle1>0;
            if(j1<0){condition1=angle1<0;}
            condition2=trans1>0;
            if(j3<0){condition2=trans1<0;}  
            condition=condition1 || condition2;          
            delay(200);
            loop5+=1;
        myservo.write(60);
        delay(500);
        }
        
            digitalWrite(M1_REN,LOW);
            digitalWrite(M1_LEN,LOW);
            digitalWrite(M2_REN,LOW);
            digitalWrite(M2_LEN,LOW);
            digitalWrite(M3_REN,LOW);
            digitalWrite(M3_LEN,LOW);
            
            analogWrite(M1_LPWM,0);
            analogWrite(M1_RPWM,0);
            analogWrite(M2_RPWM,0);
            analogWrite(M2_LPWM,0);
            analogWrite(M3_RPWM,0);
            analogWrite(M3_LPWM,0);
            delay(100);
            

        client.println("HTTP/1.1 204 No Content"); // No response body
    }
    
    else {
        // Serve the HTML page when root URL is requested
        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println("Connection: close");
        client.println();
        client.println(htmlPage);
    }

    client.stop();
}
