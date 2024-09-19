const char PAGE_MAIN[] PROGMEM = R"=====(

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    
    <title>Document</title>
</head>
<style>

    html{
        scroll-behavior: smooth;
    }

    *{
        padding: 0;
        margin: 0;
        box-sizing: border-box;
        list-style: none;
        text-decoration: none;
        
    }

    body {
        height: 100vh;
        font-family: "poppins";
        background: #090b0c;
    }

    img{
        width:100%;
    }

    section{
        padding-top: calc(8%);
        padding-left: calc(4.4%);
        background: transparent;
    }







    /* ===========================HEADER==============================*/

    header{
        background-color: #090b0c;
        box-shadow: 0 8px 16px rgba(68, 68, 68, 0.2);
        position: fixed;
        width: 100%;
        z-index: 5;
        
        
    }

    .logo{
        width: 20%;
        
        
    }

    .navbar{
        
        display: flex;
        justify-content: space-between;
        align-items: center;
        margin: 0 auto;
        width: 90%;
        padding: 10px 0;
        
    }
    .date-time {
        margin-left: 100px;
        font-size: 16px;
        color: #fff;
        font-weight: 900;
        display: flex;
        flex-direction: column; /* Alt alta sıralanacak */
        padding: 5px 15px;
    }
    .navbar h1{
        font-size: 32px;
        color: #fff;
        font-weight: 600;
        text-align: center;
    }

    /*----------------Giriş Bölümü----------------*/
    .inner_settings{
        
        display: flex;
        
        align-items: center;
        justify-content: center;
        margin: 0 auto;
        width: 75%;
        
    }

    .child_settings{
        
        width: 38%;
        
    }

    .child_settings form {
        padding: 12% 10%;
        
        box-shadow: 0 0px 8px rgb(55, 55, 55);
        border-radius: 15px;
        justify-content: center;
    }





    .child_settings form h2{
        text-align: center;
        color: #fff;
        font-weight: bold;
        font-size: 30px;
        margin-bottom: 30px;
    }

    .child_settings form label {
        text-align: left; 
        color: #fff;
        font-size: 15px;
        font-weight: 600;
        padding: 7px 35px; 
        display: block; 
        
    }


    .child_settings form input{
        display: flex;
        width: 90%;
        padding: 3.7%;
        padding-left: 5%;
        
        margin: 0 auto;
        margin-bottom: 25px;
        background: transparent;
        border: 1px solid rgb(255, 255, 255);
        font-size: 15px;
        color: #fff;
        border-radius:20px;
        resize: none;
        
        transition: .15s ease-in;
    }

    .child_settings form input:focus{

        color: #fff;
        letter-spacing: 1px;
        outline: none;
    }

    .child_settings form input:last-child{
        margin-top: 40px;
        margin-bottom: 30px;
        background: #333;
        color: #ffffff;
        cursor: pointer;
        z-index: 1;
        border-radius: 20px;
        border: none;
        outline: none;
        text-align: center;
        transition: .3s;
    }

    .child_settings form input:last-child:hover{
        background: #555;
        transition: .4s ease-in-out;
    }

    /*========================Base Device List===========================*/
    #base_devices {
        padding-left: 0;
        display: none;
    }

    .inner_base_devices {
        display: flex;
        flex-wrap: wrap; /* Kartların satırlara sığmasını sağlar */
        align-items: center;
        width: 80%;
        justify-content: space-between;
        margin: 0 auto;
        gap: 20px; /* Kartlar arasına boşluk ekler */
        
        
    }


    .inner_base_devices_child {
        flex-basis: calc(31% - 20px); /* Her satırda iki kart olması için genişlik */
        color: #f9fbfb;
        box-shadow: 0px 4px 15px rgba(0, 0, 0, 0.2); /* Daha belirgin gölge */
        border-radius: 20px; /* Kart kenarlarını daha yuvarlak yapmak için */
        border: 1px solid transparent;
        transition: all 0.5s ease;
        padding: 20px; /* İçerik boşluğunu artırır */
        text-align: center; /* Kartın içeriğini ortalar */
        cursor: pointer;
        background: #1c1c1e;
    }

    .inner_base_devices_child:hover {
        border: 1px solid #fff; /* Hover'da kenar ekler */
    }

    .inner_base_devices_child h1 {
        font-size: 18px;
        font-weight: bold;
        margin-bottom: 15px; /* Başlık ve içerik arasına boşluk */
    }

    /* İlerleme çemberi */
    .device_status_container {
        position: relative;
        width: 80px;
        height: 80px;
        border-radius: 50%;
        display: flex;
        align-items: center;
        justify-content: center;
        margin: 0 auto;
        margin-bottom:15px;
    }

    .device_status_container p {
        background: #eee;
        border-radius: 50%;
        width: 60px;
        height: 60px;
        display: flex;
        align-items: center;
        justify-content: center;
        font-size: 18px;
        font-weight: bold;
        color: #333;
        position: relative;
        z-index: 1;
    }

    .device_status_container:before {
        content: '';
        position: absolute;
        top: 5px;
        left: 5px;
        right: 5px;
        bottom: 5px;
        background: #1c1c1e;
        border-radius: 50%;
        z-index: 0;
    }

    .back-icon {
        width: 80px; /* İkon boyutu */
        height: 80px; /* İkon boyutu */
        
        
    }
    /*========================Device List===========================*/


    #devices {
        padding-left: 0;
        display: none;
    }
    .innerdevices{
        display: flex;
        flex-wrap: wrap; /* Kartların satırlara sığmasını sağlar */
        align-items: center;
        width: 80%;
        justify-content: center;
        margin: 0 auto;
        gap: 20px; /* Kartlar arasına boşluk ekler */
        
        
    }

    .innderdevices_child{
        flex-basis: calc(31% - 20px); /* Her satırda iki kart olması için genişlik */
        color: #f9fbfb;
        box-shadow: 0px 4px 15px rgba(0, 0, 0, 0.2); /* Daha belirgin gölge */
        border-radius: 20px; /* Kart kenarlarını daha yuvarlak yapmak için */
        border: 1px solid transparent;
        transition: all 0.5s ease;
        padding: 20px; /* İçerik boşluğunu artırır */
        cursor: pointer;
        position: relative; /* Ensures .dot_top is positioned relative to this container */

        background: #1c1c1e;
    }

    .innderdevices_child:hover{
        border: 1px solid #fff;
    }

    .innderdevices_child h1{
        font-size: 16px;
        font-weight: bold;
        margin: 5px 0;  
        padding-left: 8px;
        
        padding-bottom: 8px;
    }

    .innderdevices_child h2{
        
        font-size: 12px;
        font-weight: bold;
        margin: 5px 0; 
        padding-left: 8px;
        padding-top: 8px;
        margin-top:8px;
    }

    .innderdevices_child p{
        text-align: center;
        font-size: 16px;
        margin: 5px 0;
    }


    #back_button_devices {
        display: flex;
        flex-direction: column; /* İkon ve yazının dikeyde ortalanmasını sağlar */
        align-items: center; /* Ortalamak için */
        justify-content: center; /* Ortalamak için */
        width: calc(31% - 20px); /* Diğer kartlarla aynı genişlikte olsun */
        color: #fff;
        box-shadow: 0px 4px 15px rgba(0, 0, 0, 0.2);
        border-radius: 20px;
        border: 1px solid transparent;
        transition: all 0.5s ease;
        padding: 20px;
        background: #1c1c1e;
    }

    #back_button_devices:hover {
        border: 1px solid #fff;
    }

    #back_button_devices h1 {
        font-size: 16px;
        font-weight: bold;
        margin: 5px 0;
        padding-left: 8px;
        padding-bottom: 8px;
    }

    .back-icon_devices {
        width: 80px; /* İkon boyutu */
        height: 80px; /* İkon boyutu */
        
    }

    .status-dots {
        display: inline-flex;
        align-items: center;
    }
    .dot_top {
        position: absolute;
        top: 15px; /* Adjust as needed */
        right: 15px; /* Adjust as needed */
        width: 8px;
        height: 8px;
        background-color: red;
        border-radius: 50%;
    }
    .dot {
        display: inline-block;
        width: 5px;
        height: 5px;
        margin: 0 2px;
        background-color: currentColor;
        border-radius: 50%;
        animation: bounce 1.5s infinite ease-in-out;
    }

    .dot:nth-child(2) {
        animation-delay: 0.2s;
    }

    .dot:nth-child(3) {
        animation-delay: 0.4s;
    }

    @keyframes bounce {
        0%, 20%, 50%, 80%, 100% {
            transform: translateY(0);
        }
        40% {
            transform: translateY(-12px);
        }
        60% {
            transform: translateY(-6px);
        }
    }


    @media  screen and (max-width:1200px){
        section{
            padding-top: calc(15%);

        }
        .navbar{
            width:100%;
            flex-direction: column;
        }
        .logo{
            width: 20%;
            margin-bottom: 5px;
        }
        .date-time {
            display:none;
            
        }
        .navbar h1{
            font-size: 26px;

        }


        .inner_settings{
        

            width: 100%;
        }
        .child_settings{
            
            
            width: 50%;
        }

    }



    @media  screen and (max-width:770px){
        section{
            padding-top: calc(25%);
            padding-left: 0;
        }
        .navbar{
            width:100%;
            flex-direction: column;
        }
        .logo{
            width: 40%;
            margin-bottom: 5px;
        }
        .date-time {
            display:none;
            
        }
        .navbar h1{
            font-size: 20px;

        }
        .inner_settings{
        
            
            width: 100%;
        }
        .child_settings{
            
            width: 80%;
        }
        .inner_base_devices_child {
            flex-basis: calc(50% - 20px); /* Her satırda iki kart olması için genişlik */

        }
        .innderdevices_child{
            flex-basis: 100%;/* Her satırda iki kart olması için genişlik */

        }

    }


</style>





    <body onload="process()">
        <header>
            <nav class="navbar">
                <div class="logo">
                    <img src="logo" alt="logo">
                </div>
                <h1>P2P Listen Mode</h1>
                <div class="date-time">
                    <span id="date">Date: DD.MM.YYYY</span>
                    <span id="time">Time: 00:00:00</span>
                </div>
            </nav>
        </header>

        <!--Giriş ekranı-->
        <section id="settings_menu">
            <div class="inner_settings">
                <div class="child_settings">
                    <form id="settings_form" action="#">
                        <h2>Settings</h2>
                        <label for="p2p_conf">P2P Configuration</label>
                        <input type="text" id="field1" name="p2p_conf" value="868000000:7:125:0:8:22" required>
                        <label for="p_recv">Input Parameter (PRECV)</label>
                        <input type="text" id="field2" name="p_recv" value="65534" required>
                        <label for="mahal_no">Mahal No</label>
                        <input type="text" id="field3" name="mahal_no" required>
                        <input type="submit" value="Save Settings" id="saveButton">
                    </form>
                </div>
            </div>
        </section>

        <!-- ANA CİHAZLAR -->
            <section id="base_devices">
                <div class="inner_base_devices">
                    <div class="inner_base_devices_child" id="sifon">
                        <h1>Sifon</h1>
                        <div class="device_status_container">
                            <p>0/0</p>
                        </div>
                    </div>

                    <div class="inner_base_devices_child" id="sabunluk">
                        <h1>Sabunluk</h1>
                        <div class="device_status_container">
                            <p>0/0</p>
                        </div>
                    </div>
                    <div class="inner_base_devices_child" id="pisuvar">
                        <h1>Pisuvar</h1>
                        <div class="device_status_container">
                            <p>0/0</p>
                        </div>
                    </div>
                    <div class="inner_base_devices_child" id="pecetelik">
                        <h1>Peçetelik</h1>
                        <div class="device_status_container">
                            <p>0/0</p>
                        </div>
                    </div>
                    <div class="inner_base_devices_child" id="rulo">
                        <h1>Rulo</h1>
                        <div class="device_status_container">
                            <p>0/0</p>
                        </div>
                    </div>

                    <div class="inner_base_devices_child" id="back_main">
                        <h1>Back</h1>
                        <img src="back" alt="Back Icon" class="back-icon">
                        
                    </div>
                </div>
            </section>
        
        
        
        
        <!-- CİHAZLAR -->
        <section id="devices">
            <div class="innerdevices">
                <div class="innderdevices_child" id="device_template" style="display: none;">
                    <span class="dot_top"></span>
                    <h1>Device Name</h1>
                    <p>Sensor Value: 0/0<br>Battery: 0/0</p>
                    <h2>Status: <span class="status-dots">Waiting<span class="dot"></span><span class="dot"></span><span class="dot"></span></span></h2>
                </div>
                <div id="back_button_devices" class="innderdevices_child">
                    <h1>Back</h1>
                    <img src="back" alt="Back Icon" class="back-icon_devices">
                </div>
            </div>
        </section>
        
        



    </body>



    <script type="text/javascript">
        
       

        
       
        var deviceValues={};
        
        var pisuvarID = [], sifonID = [], sabunlukID = [], zPeceteID = [], ruloID = [];

        const sabunlukContainer = document.getElementById('sabunluk');
        const sifonContainer = document.getElementById('sifon');
        const pisuvarContainer = document.getElementById('pisuvar');
        const pecetelikContainer = document.getElementById('pecetelik');
        const ruloContainer = document.getElementById('rulo');



        const saveButton = document.getElementById('saveButton');
        const backButton = document.getElementById('back_main');
        const backtoDevices = document.getElementById('back_button_devices');


        const field1 = document.getElementById('field1');
        const field2 = document.getElementById('field2');
        const field3 = document.getElementById('field3');


        const mainMenu = document.getElementById('settings_menu');
        





        var xmlHttp = createXmlHttpObject();

        function createXmlHttpObject() {
            return window.XMLHttpRequest ? new XMLHttpRequest() : new ActiveXObject("Microsoft.XMLHTTP");
        }

        function toggleElementVisibility(elementId, show) {
            document.getElementById(elementId).style.display = show ? 'flex' : 'none';
        }



        //Dinlemeyi başlatma kısmı
        saveButton.addEventListener('click', (event) => {
            event.preventDefault();
            saveButton.disabled = true;
            const field1Value = field1.value.trim();
            const field2Value = field2.value.trim();
            const field3Value = field3.value.trim();
            const params = field1Value.split(':'); // Split by ':'

            if (params.length !== 6) {
                alert("P2P Configuration Error.");
                return;
            }

            const intParams = params.map(param => parseInt(param, 10));

            // Ensure all params are valid integers
            if (intParams.some(isNaN)) {
                alert("P2P Configuration Error.");
                return;
            }

            // Validate params
            if (!(intParams[0] >= 150000000 && intParams[0] <= 960000000 &&
                intParams[1] >= 5 && intParams[1] <= 12 &&
                [125, 250, 500].includes(intParams[2]) &&
                [0, 1, 2, 3].includes(intParams[3]) &&
                intParams[4] >= 2 && intParams[4] <= 65535 &&
                intParams[5] >= 5 && intParams[5] <= 22)) {
                alert("P2P Configuration Error.");
                return;
            }

            // Validate field2Value
            const field2ValueInt = parseInt(field2Value, 10);
            if (isNaN(field2ValueInt) || ![65534,65535].includes(field2ValueInt)) {
                alert("PRECV Error.");
                return;
            }
         
            
            if (!field1Value || !field2Value || !field3Value) {
                alert("Fields cannot be empty.");
                return;
            }



            resetModuleValues();

            fetchMahalData(field3Value);
            
        });



        //Mahal No nun veri tabanından çekilmesi
        function fetchMahalData(mahalNo) {
            fetch('/veri.json')
                .then(response => {
                    if (!response.ok) throw new Error('Network response was not ok');
                    return response.json();
                })
                .then(data => {
                    const mahalData = data.data.find(d => d.tag === mahalNo);
                    if (mahalData) {
                        
                        updateModuleValues(mahalData);
                        updateUIForListening(mahalData);
                        sendConfigToServer(mahalData.id, mahalData);
                        
                    } else {
                        saveButton.disabled = false;
                        alert("Mahal No is not registered in the system.");
                    }
                })
                .catch(error => {
                    saveButton.disabled = false;
                    console.error('Fetch operation error:', error);
                    alert("There was an error fetching data. Please try again later.");
                });
        }



        function updateModuleValues(mahalData) {
            deviceValues = {
                pisuvar: parseInt(mahalData.pisuvar, 10),
                sifon: parseInt(mahalData.sifon, 10),
                sabunluk: parseInt(mahalData.sabunluk, 10),
                pecetelik: parseInt(mahalData.peçetelik, 10),
                rulo: parseInt(mahalData.rulo, 10)
            };
        }



        // Ayarları kaydettikten sonra kaç adet cihaz olduğunun güncellenmesi
   
        function updateUIForListening(mahalData) {
            const containers = document.querySelectorAll('.device_status_container p');
            const containersProgress = document.querySelectorAll('.device_status_container');
            
            // Loop through each container and update its content
            containers.forEach(container => {
                // Get the ID of the parent div
                const parentId = container.closest('.inner_base_devices_child').id;

                // Update the text content based on the ID
                if (deviceValues[parentId] !== undefined) {
                    container.innerHTML = `0/${deviceValues[parentId]}`;
                }
            });

            containersProgress.forEach(container => {
                // Get the text content of the p element inside this container
                const text = container.querySelector('p').innerHTML;
                const [current, total] = text.split('/').map(Number);

                // Calculate progress percentage
                let progressPercentage = total > 0 ? (current / total) * 100 : 100;
                // Calculate angle for conic-gradient
                const angle = (progressPercentage / 100) * 360;

                // Set background dynamically based on progress
                container.style.background = `conic-gradient(
                    #00ff00 0deg ${angle}deg,   /* Green part */
                    #ff0000 ${angle}deg 360deg  /* Red part */
                )`;
            });

            document.getElementById('base_devices').style.display = 'flex';
            document.getElementById('settings_menu').style.display = 'none';
            
            addMultipleDevices("sifon",deviceValues.sifon);
            addMultipleDevices("sabunluk",deviceValues.sabunluk);
            addMultipleDevices("pecetelik",deviceValues.pecetelik);
            addMultipleDevices("pisuvar",deviceValues.pisuvar);
            addMultipleDevices("rulo",deviceValues.rulo);
        }




        //Ana menüye geri dönme

        backButton.addEventListener('click', (event) => {
            event.preventDefault();
            document.getElementById('settings_menu').style.display = 'flex';
            document.getElementById('base_devices').style.display = 'none';
            resetModuleValues();
            removeAllDevices();
            sendStopSignal();
            saveButton.disabled = false;
        }); 


        //Ana Cihazlara geri dönme
        backtoDevices.addEventListener('click', (event) => {
            event.preventDefault();
            document.getElementById('base_devices').style.display = 'flex';
            document.getElementById('devices').style.display = 'none';
            
        });  

        //Değerlerin hepsini sıfırlama
        function resetModuleValues() {
           
            pisuvarID = [], sifonID = [], sabunlukID = [], zPeceteID = [], ruloID = [];
            deviceValues = {};
        }


        //Device containerlerine basma

        sifonContainer.addEventListener('click', (event) => {
            event.preventDefault();
            showDevicesByType('sifon');
            document.getElementById('devices').style.display = 'flex';
            document.getElementById('base_devices').style.display = 'none';
        });  

        sabunlukContainer.addEventListener('click', (event) => {
            event.preventDefault();
            showDevicesByType('sabunluk');
            document.getElementById('devices').style.display = 'flex';

            document.getElementById('base_devices').style.display = 'none';
            
        }); 

        pecetelikContainer.addEventListener('click', (event) => {
            event.preventDefault();
            showDevicesByType('pecetelik');
            document.getElementById('devices').style.display = 'flex';

            document.getElementById('base_devices').style.display = 'none';
            
        }); 

        pisuvarContainer.addEventListener('click', (event) => {
            event.preventDefault();
            showDevicesByType('pisuvar');
            document.getElementById('devices').style.display = 'flex';

            document.getElementById('base_devices').style.display = 'none';
            
        }); 

        ruloContainer.addEventListener('click', (event) => {
            event.preventDefault();
            showDevicesByType('rulo');
            document.getElementById('devices').style.display = 'flex';

            document.getElementById('base_devices').style.display = 'none';
            
                 
        }); 

        function showDevicesByType(type) {
            document.querySelectorAll('.device').forEach(device => {
                if (!device.id.includes(type)) {
                    device.style.display = 'none';
                }else{
                    device.style.display = 'block';
                }

            });
        }

        
        function addDevice(name, sensorValue, batteryValue,  id, counter) {
            const deviceTemplate = document.getElementById('device_template');
            const newDevice = deviceTemplate.cloneNode(true);

            newDevice.style.display = 'block';
            newDevice.querySelector('h1').textContent = name;
            newDevice.querySelector('p').innerHTML = `Sensor Value: ${sensorValue}<br>Battery: ${batteryValue}`;

            // Update status with animated dots
            const statusElement = newDevice.querySelector('h2');
            statusElement.innerHTML = `Status: <span class="status-dots">Waiting <span class="dot">.</span><span class="dot">.</span><span class="dot">.</span></span>`;

            newDevice.id = `device_${id}_${counter}`;
            newDevice.classList.add('device'); // Add a common class name

            // Insert the new device before the back button
            const innerDevices = document.querySelector('.innerdevices');
            const backButton = document.getElementById('back_button_devices');
            innerDevices.insertBefore(newDevice, backButton);
        }


        function addMultipleDevices(id,count) {
            for (let i = 1; i <= count; i++) {
                addDevice(`Device ${i}`, '0/0', '0/0',id,i);
            }
        }

        function updateDeviceContent(deviceId, sensorValue, batteryValue) {
            const device = document.getElementById(deviceId);
            if (device) {
                
                device.querySelector('p').innerHTML = `Sensor Value: ${sensorValue}<br>Battery: ${batteryValue}`;
                device.querySelector('h2').textContent = `Status: Received`;
                const dotTopElement = device.querySelector('.dot_top');
                dotTopElement.style.backgroundColor = 'green';
            }
        }

        function removeAllDevices() {
            const devices = document.querySelectorAll('.device');
            devices.forEach(device => device.remove());
        }






        //Verilerin Dinlenmesi
        
        function send(msg) {
            let moduleNumber = msg.substring(0, 2);
            let id = msg.substring(2, 4);
            const idInt = parseInt(id, 10);

            const updateIDArray = (array, id, msg) => {
                let index = array.findIndex(item => item[0] === id);
                if (index === -1) {
                    array.push([id, parseInt(msg.substring(4, 6), 16), parseInt(msg.substring(6, 8), 16), msg.substring(4, 6), msg.substring(6, 8)]);
                } else {
                    array[index][1] = parseInt(msg.substring(4, 6),16);
                    array[index][2] = parseInt(msg.substring(6, 8),16);
                    array[index][3] = msg.substring(4, 6);
                    array[index][4] = msg.substring(6, 8);
                }
            };

            switch (moduleNumber) {
                case "41":
                    updateIDArray(sabunlukID, id, msg);
                    updateContainerContent("sabunluk", sabunlukID.length);
                    updateDeviceContent(`device_sabunluk_${idInt - 30}`, 
                    `${sabunlukID[sabunlukID.length - 1][2]} / ${sabunlukID[sabunlukID.length - 1][4]}`, 
                    `${sabunlukID[sabunlukID.length - 1][1]}% / ${sabunlukID[sabunlukID.length - 1][3]}`);
                    break;
                    
                case "42":
                    updateIDArray(zPeceteID, id, msg);
                    updateContainerContent("pecetelik", zPeceteID.length);
                    updateDeviceContent(`device_pecetelik_${idInt - 30}`, 
                    `${zPeceteID[zPeceteID.length - 1][2]} / ${zPeceteID[zPeceteID.length - 1][4]}`, 
                    `${zPeceteID[zPeceteID.length - 1][1]}% / ${zPeceteID[zPeceteID.length - 1][3]}`);
                    break;
                    
                case "43":
                    updateIDArray(ruloID, id, msg);
                    updateContainerContent("rulo", ruloID.length);
                    updateDeviceContent(`device_rulo_${idInt - 30}`, 
                    `${ruloID[ruloID.length - 1][2]} / ${ruloID[ruloID.length - 1][4]}`, 
                    `${ruloID[ruloID.length - 1][1]}% / ${ruloID[ruloID.length - 1][3]}`);
                    break;
                    
                case "44":
                    updateIDArray(pisuvarID, id, msg);
                    updateContainerContent("pisuvar", pisuvarID.length); // Corrected 'isuvarID' to 'pisuvarID'
                    updateDeviceContent(`device_pisuvar_${idInt - 30}`, 
                    `${pisuvarID[pisuvarID.length - 1][2]} / ${pisuvarID[pisuvarID.length - 1][4]}`, 
                    `${pisuvarID[pisuvarID.length - 1][1]}% / ${pisuvarID[pisuvarID.length - 1][3]}`);
                    break;
                    
                case "45":
                    updateIDArray(sifonID, id, msg);
                    updateContainerContent("sifon", sifonID.length);
                    updateDeviceContent(`device_sifon_${idInt - 30}`, 
                    `${sifonID[sifonID.length - 1][2]} / ${sifonID[sifonID.length - 1][4]}`, 
                    `${sifonID[sifonID.length - 1][1]}% / ${sifonID[sifonID.length - 1][3]}`);
                    break;
            }
        }
        
        function updateContainerContent(containerId, newValue) {
            // Get the container by its ID
            const container = document.getElementById(containerId);

            if (container) {
                // Find the <p> tag within the container and update its content
                const pElement = container.querySelector('.device_status_container p');

                if (pElement) {
                    // Split the current text content (e.g., "0/10")
                    const [current, total] = pElement.innerHTML.split('/');

                    // Update the first part with the new value
                    pElement.innerHTML = `${newValue}/${total}`;
                }

                // Get the updated text content from the <p> element
                const text = container.querySelector('p').innerHTML;
                const [current, total] = text.split('/').map(Number);

                // Calculate progress percentage
                let progressPercentage = total > 0 ? (current / total) * 100 : 100;

                // Calculate angle for conic-gradient
                const angle = (progressPercentage / 100) * 360;

                // Set background dynamically based on progress
                container.querySelector('.device_status_container').style.background = `conic-gradient(
                    #00ff00 0deg ${angle}deg,   /* Green part */
                    #ff0000 ${angle}deg 360deg  /* Red part */
                )`;
            }
        }


        //ESP ile Haberleşme

       function response() {
            var xmlResponse = xmlHttp.responseXML;
            var xmldoc = xmlResponse.getElementsByTagName("id");
            var message = xmldoc[0].firstChild.nodeValue;
            var dt = new Date();

            // Update time and date
            document.getElementById("time").innerHTML = `TIME: ${dt.toLocaleTimeString()}`;
            document.getElementById("date").innerHTML = `DATE: ${dt.toLocaleDateString()}`;


            send(message);
        }

        function sendConfigToServer(id, mahalData) {
            const xhttp = new XMLHttpRequest();
            xhttp.open("PUT", `BUTTON?config=${encodeURIComponent(field1.value)}&precv=${encodeURIComponent(field2.value)}&id=${encodeURIComponent(id)}&sabunluk=${encodeURIComponent(deviceValues.sabunluk)}&sifon=${encodeURIComponent(deviceValues.sifon)}&pisuvar=${encodeURIComponent(deviceValues.pisuvar)}&zPecete=${encodeURIComponent(deviceValues.pecetelik)}&rulo=${encodeURIComponent(deviceValues.rulo)}`, true);
            xhttp.send();
        }

        function sendStopSignal() {
            var xhttp = new XMLHttpRequest();
            xhttp.open("PUT", "BUTTON_STOP?stop=0", true);
            xhttp.send();
        }

        function process() {
            if (xmlHttp.readyState === 0 || xmlHttp.readyState === 4) {
                xmlHttp.open("PUT", "xml", true);
                xmlHttp.onreadystatechange = response;
                xmlHttp.send(null);
            }
            setTimeout(process, 100);
        }

 


    </script>




</html>
)=====";
