class Gru() :
    GruHealth = 100
    GruEnergy = 500 
    ElectricProdUses = 5
    MegaMagnetUses = 3
    KalmanMissileUses = 1
    SelectivePermeabilityUses = 2
    DoesGruHaveEnergyProjectedBarrierGun = 0
    DoesGruHaveSelectivePermeability = 0
    shieldPentration = 1
    
    
    def DamagedG(Damaged) :
        
        Gru.GruHealth -= Damaged - Gru.DoesGruHaveEnergyProjectedBarrierGun* 0.4 * Damaged - Gru.DoesGruHaveSelectivePermeability* 0.9 * Damaged


class GruWeapons(Gru) :
        
    
    def FreezeGun(self) :
        
        Gru.GruEnergy -= 50
        VectorWeapons().DamagedV(11)
        
    
    def ElectricProd(self) :
        
            Gru.GruEnergy -= 88
            Vector().DamagedV(18)
            Gru.ElectricProdUses -= 1
        
    
    def MegaMagnet(self) :
        
            Gru.GruEnergy -= 92
            Vector().DamagedV(10)
            Gru.MegaMagnetUses -= 1

    
    def KalmanMissile(self) :
            Gru.shieldPentration = 0
            Gru.GruEnergy -= 120
            Vector().DamagedV(20)
            Gru.shieldPentration = 1
            Gru.KalmanMissileUses -= 1
        
        

class GruShields(Gru) :
    
    
    def EnergyProjectedBarrierGun() :
        
        Gru.DoesGruHaveEnergyProjectedBarrierGun = 1
    
    
    def SelectivePermeability() :
        
            Gru.DoesGruHaveSelectivePermeability = 1  
            Gru.SelectivePermeabilityUses -= 1


class Vector() :
    
    
    VectorHealth = 100
    VectorEnergy = 500
    PlasmaGrenadesUses = 8
    SonicResonanceCannonUses = 3
    QuantumDeflectorUses = 3
    DoesVectorHaveEnergyNetTrap = 0 
    DoesVectorHaveQuantumDeflector = 0
    
    def DamagedV(self,Damaged) :
        
        Vector.VectorHealth -= Damaged - Vector.DoesVectorHaveEnergyNetTrap * 0.32 * Damaged * Gru.shieldPentration - Vector.DoesVectorHaveQuantumDeflector * 0.8 * Damaged * Gru.shieldPentration


class VectorWeapons(Vector) :
    
    
    def LaserBlasters(self) :
        Vector.VectorEnergy -= 40
        Gru.DamagedG(8)
   
    
    def PlasmaGrenades(self) :
            Vector.VectorEnergy -= 56
            Gru.DamagedG(13)
            Vector.PlasmaGrenadesUses -= 1
   
    
    def SonicResonanceCannon(self) :
            Vector.VectorEnergy -= 100
            Gru.DamagedG(22)
            Vector.SonicResonanceCannonUses -= 1


class VectorShields(Vector) :
    
    
    def EnergyNetTrap() :
        Vector.VectorEnergy -= 15
    
    
    def QuantumDeflector() : 
            Vector.VectorEnergy -= 40
            Vector.QuantumDeflectorUses -= 1



    


On = 1
Gru1 = Gru()
Vector1 = Vector()
GruW = GruWeapons()
GruS = GruShields()
VectorW = VectorWeapons()
VectorS = VectorShields()

print("At any time type 99 and end the turn to exit")

while (GruW.GruHealth >= 0 and VectorW.VectorHealth >= 0)*On  :
    
    
    print("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\") 
    print(f"\nGru Health: {GruW.GruHealth}\tVector Health {VectorW.VectorHealth}\nGru Energy: {GruW.GruEnergy}\tVector Energy: {VectorW.VectorEnergy}\n")
    print(f"Gru:\nNo.\tWeapons\t\t\tEnergy\t\tDamage\t\tResources\n1\tFreeze Gun\t\t50\t\t11\t\tInf\n2\tElectric Prod\t\t88\t\t18\t\t{GruW.ElectricProdUses}\n3\tMega Magnet\t\t92\t\t10\t\t{GruW.MegaMagnetUses}\n4\tKalman Missile\t\t120\t\t20\t\t{GruW.KalmanMissileUses}\n\nNo.\tShield\t\t\t\t\tEnergy\t\tSave\t\tResources\n5\tEnergy Projected BarrierGun\t\t20\t\t40%\t\tInf\n6\tSelective Permeability\t\t50\t\t90%\t\t{GruW.SelectivePermeabilityUses}\n")
    print(f"Vector:\nNo.\tWeapons\t\t\tEnergy\t\tDamage\t\tResources\n1\tLaser Blasters\t\t40\t\t8\t\tInf\n2\tPlasma Grenades\t\t56\t\t13\t\t{VectorW.PlasmaGrenadesUses}\n3\tSonic Resonance Cannon\t100\t\t22\t\t{VectorW.SonicResonanceCannonUses}\n\nNo.\tShield\t\t\tEnergy\t\tSave\t\tResources\n4\tEnergy Net Trap\t\t15\t\t32%\t\tInf\n5\tQuantum Deflector\t40\t\t80%\t\t{VectorW.QuantumDeflectorUses}")
    
    
    GruOption = int(input("Choose Gur's action:"))
    VectorOption = int(input("Choose Vector's action:"))
    
    if Gru1.ElectricProdUses ==0 or Gru1.MegaMagnetUses ==0 or Gru1.KalmanMissileUses ==0 or Gru1.SelectivePermeabilityUses ==0 or Vector1.PlasmaGrenadesUses ==0 or Vector1.SonicResonanceCannonUses ==0 or Vector1.QuantumDeflectorUses ==0 :
        print("Can't use")
        continue
    
    if GruW.GruEnergy <= 0 or VectorW.VectorEnergy <=0 :
        print("Can't use")
        continue
    
    if VectorOption == 99 :
        On = 0
    
    if GruOption == 1 :
        
        GruW.FreezeGun()
    
    elif GruOption == 2 :
        
        GruW.ElectricProd()
    
    elif GruOption == 3 :
        
        GruW.MegaMagnet()
    
    elif GruOption == 4 :
        
        GruW.KalmanMissile()
        
    
    if VectorOption == 1 :
        
        VectorW.LaserBlasters()
    
    elif VectorOption == 2 :
        
        VectorW.PlasmaGrenades()
    
    elif VectorOption == 3 :
    
        VectorW.SonicResonanceCannon()
    
    if VectorOption == 99 or GruOption == 99:
        On = 0 
print("Thanks for playing")