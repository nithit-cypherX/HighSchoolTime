class Scene {
    start(){}
    draw(ctx){}
    onKey(event){}
}
class CountDownScene extends Scene{
    constructor(){
        super()
            this.value = 3
        
        }
        
    start(){
        let interval = setInterval(()=>{
            if(this.value == 0){
                clearInterval(interval)
                activeScene = new GameScene()
                activeScene.start()
            }else{
                this.value --;
            }
        }, 1000)
    }
    draw(ctx){
        ctx.font = "80px Georgia";
        ctx.fillStyle = "red";
        ctx.fillText("" + this.value, 10, 50);
    }
}
class GameScene extends Scene{
    constructor(){
        super()
    this.size = 50
    this.max_size = 200
    this.shrink_step = 15
    this.grow_step = 5
    this.end = false
    this.score = 0
    this.forbid = false
    this.forbidCount = 0
    }
    start(){
        let interval = setInterval(()=>{
            if(Math.random() > 0.97){
                this.forbid = true
            }
            if(this.forbid){
                this.forbidCount++;
                if(this.forbidCount >= 20){
                    this.forbid = false
                    this.forbidCount = 0
                }
            }
            this.grow()
            this.score += 10
            if(this.end){
                clearInterval(interval)
            }
        }, 100)
    }
    shrink(){
        if(this.forbid){
            this.score -= 100
            return
        }
        if(this.size > 20) this.size -= this.shrink_step
    }
    grow(){
        if(this.forbid)
            return

        if(this.size < this.max_size)
            this.size += this.grow_step
        else
            this.end = true
    }
    draw(ctx){        
        ctx.fillStyle = this.end ? 'red' : 
            (this.forbid ? 'yellow': 'green')
        ctx.beginPath()
        ctx.arc(200, 200, this.size, 0, 2 * Math.PI, false)
        ctx.fill()
        if(!this.end){
            ctx.font = "40px Georgia";
            ctx.fillStyle = "red";
            ctx.fillText("" + this.score, 200, 200);
        }
    }
    onKey(event){
        if(!this.end && event.keyCode == 32)
            this.shrink()
    }
}