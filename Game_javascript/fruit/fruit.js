class Scene {
    start() { }
    draw(ctx) { }
    onKey(event) { }
}
class CountDownScene extends Scene {
    constructor() {
        super()
        this.value = 3
    }
    start() {
        let interval = setInterval(() => {
            if (this.value == 0) {
                clearInterval(interval)
                activeScene = new GameScene()
                activeScene.start()
            } else {
                this.value--;
            }
        }, 1000)
    }
    draw(ctx) {
        ctx.font = "80px Georgia";
        ctx.fillStyle = "red";
        ctx.fillText("" + this.value, 10, 50);
    }
}
class GameScene extends Scene {

    constructor() {
        super()
        //this.end = false
        ////this.x = 150
        this.x_step = 10
        this.y_step = 10
        //this.score = 0
        this.box_x = 150
        this.box_y = 150
        ////this.y = 150
        //this.x = Math.floor(Math.random() * 400)
        // this.y = Math.floor(Math.random() * 400)
    }

    start() {
        // let interval = setInterval(() => {
        //     this.left()
        //     this.right()
        //     //this.down()
        //    // this.up()
        //   //  this.crash()
        //     //if (this.end) {
        //        // clearInterval(interval)
        //     //}
        // }, 100)
    }
    left() {
        if (this.box_x > 0) this.box_x -= this.x_step
    }
    right() {
        if (this.box_x+100 < 300) this.box_x += this.x_step
    }
    down() {
        if (this.box_y+100 < 300) this.box_y += this.y_step 
    }
    up() {
        if (this.box_y > 0) this.box_y -= this.y_step 
    
    }          
    
    
   // crash(){
      //  if(this.y > 370)
       //     this.end = true 
    //  }
    draw(ctx) {
        ctx.fillStyle = 'blue'
        ctx.beginPath()
        ctx.fillRect(this.box_x,this.box_y,50,50)
        ctx.fill()

       

        /*if(this.end ){
            ctx.fillStyle = 'black'
            ctx.beginPath()
            ctx.fillRect(200, 20, 20, 20)
            ctx.fill()
            }*/
    }
    onKey(event) {
        if (event.keyCode == 37)
            this.left()
        if (event.keyCode == 39)
            this.right()
        if (event.keyCode == 40)
            this.down()
        if (event.keyCode == 38)
            this.up()
    }

}