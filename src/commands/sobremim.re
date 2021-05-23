open CommandRegister
open Schema
let register = () => {
  name: ["sobremim"],
  description: "sobremim",
  run: (message, _) => {
    let args = Args.parse(message.content)
    if (Array.length(args) > 0){
        Schema.set(User.users, message.author.id, {
            aboutMe: Js.Array.joinWith(" ", args)
        })
        Discord.Message.reply(message, "Voce mudou seu sobremim com sucesso" |> Discord.toStr)
    }else {
        let user = Schema.get(User.users,message.author.id)
        Discord.Message.reply(message, user.aboutMe |> Discord.toStr)
    }
  }
}
