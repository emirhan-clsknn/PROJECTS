const express = require('express');
const mongoose = require('mongoose');
const bodyParser = require('body-parser');
const path = require('path');

const app = express();
app.use(bodyParser.json());
app.set('view engine', 'ejs');
app.use(express.urlencoded({ extended: true }));

// MongoDB bağlantısı
async function connectToDatabase() {
    try {
        await mongoose.connect("mongodb+srv://emirhanData:Osan123456.@cluster0.qnpus.mongodb.net/myDatabase?retryWrites=true&w=majority");
        console.log("Veritabanına başarıyla bağlanıldı.");
    } catch (error) {
        console.error("Veritabanına bağlanırken bir hata oluştu:", error);
    }
}
connectToDatabase();

// MongoDB şeması
const userSchema = new mongoose.Schema({
    name: { type: String, required: true },
    surname: { type: String, required: true },
    token: { type: String, required: true, unique: true }, // Token benzersiz
    balance: { type: Number, default: 0 }
});
const User = mongoose.model('User', userSchema);

// ESP32'den gelen token ve buton bilgisi kontrol API'si
app.post('/checkCard', async (req, res) => {
    console.log("Yeni bir istek alındı.");

    const { token, button } = req.body;
    if (!token || !button) {
        console.log("Eksik token veya buton bilgisi.");
        return res.status(400).send('Eksik giriş.');
    }

    let deductAmount = 0;
    switch (button) {
        case "1":
            deductAmount = 5;
            break;
        case "2":
            deductAmount = 10;
            break;
        case "3":
            deductAmount = 15;
            break;
        case "4":
            deductAmount = 20;
            break;
        default:
            console.log("Geçersiz buton.");
            return res.status(400).send('Geçersiz buton.');
    }

    try {
        const user = await User.findOne({ token });
        if (user) {
            if (user.balance >= deductAmount) {
                user.balance -= deductAmount;
                await user.save();
                console.log(`Kullanıcı bulundu: ${user.name} ${user.surname}, Yeni bakiye: ${user.balance}`);
                return res.send('OK');
            } else {
                console.log("Yetersiz bakiye.");
                return res.send('FAIL');
            }
        } else {
            console.log("Token eşleşen kullanıcı bulunamadı.");
            return res.send('FAIL');
        }
    } catch (error) {
        console.error("Bir hata oluştu:", error);
        return res.status(500).send('FAIL');
    }
});

// Admin paneli
app.get('/admin', async (req, res) => {
    try {
        const users = await User.find();
        res.render('admin', { users });
    } catch (error) {
        res.status(500).send('Bir hata oluştu.');
    }
});

// Yeni kullanıcı ekleme
app.post('/admin/addUser', async (req, res) => {
    const { name, surname, token, balance } = req.body;
    if (!name || !surname || !token || isNaN(balance)) {
        return res.status(400).send('Eksik veya hatalı giriş.');
    }
    try {
        const existingUser = await User.findOne({ $or: [{ name, surname }, { token }] });
        if (existingUser) {
            return res.status(400).send('Bu isim ve soyisim veya token ile bir kullanıcı zaten mevcut.');
        }
        const newUser = new User({ name, surname, token, balance: parseInt(balance) });
        await newUser.save();
        res.redirect('/admin');
    } catch (error) {
        if (error.code === 11000) {
            res.status(400).send('Bu token ile bir kullanıcı zaten mevcut.');
        } else {
            res.status(500).send('Kişi eklenirken bir hata oluştu.');
        }
    }
});

// Kullanıcıya bakiye ekleme
app.post('/admin/addBalance', async (req, res) => {
    const { userId, balance } = req.body;
    if (!userId || isNaN(balance)) {
        return res.status(400).send('Eksik veya hatalı giriş.');
    }
    try {
        const user = await User.findById(userId);
        if (user) {
            user.balance += parseInt(balance);
            await user.save();
            res.redirect('/admin');
        } else {
            res.status(404).send('Kullanıcı bulunamadı.');
        }
    } catch (error) {
        res.status(500).send('Bakiye eklenirken bir hata oluştu.');
    }
});

// Statik dosyalar
app.use('/public', express.static(path.join(__dirname, 'public')));

// Server başlatma
app.listen(3000, () => {
    console.log('Server 3000 portunda çalışıyor');
});
